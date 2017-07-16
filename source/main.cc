#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <set>

#include <iostream>

class Application
{
public:
  virtual void run() = 0;
};

const std::vector<const char*> validationLayers =
#if NDEBUG
{ };
#else
{
  "VK_LAYER_LUNARG_standard_validation"
};
#endif

const std::vector<const char*> deviceExtensions = {
  VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

bool checkValidationLayerSupport() {
  uint32_t layer_count = 0;
  vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
  std::vector<VkLayerProperties> availableLayers(layer_count);
  vkEnumerateInstanceLayerProperties(&layer_count, availableLayers.data());

  std::cout << "available validation layers: " << layer_count << "\n";

  for(const char* layer_name : validationLayers) {
    std::cout << "checking validation layer: " << std::string(layer_name) << "\n";
    auto found = std::find_if(std::begin(availableLayers), std::end(availableLayers),
                      [layer_name](auto const& layer) {
                        return (std::strcmp(layer_name, layer.layerName) == 0);
                      });
  }
  return true;
}

std::vector<const char*> getRequiredExtensions() {
  std::vector<const char*> extensions;
  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  for(uint32_t index = 0; index < glfwExtensionCount; ++index)
  {
    extensions.push_back(glfwExtensions[index]);
  }
  if(!validationLayers.empty())
  {
    extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
  }
  return extensions;
}

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT msgFlags, VkDebugReportObjectTypeEXT objType, uint64_t srcObject,
                                       size_t location, int32_t msgCode, const char *pLayerPrefix, const char *pMsg,
                                       void *pUserData) {

    std::cerr << "validation layer: " << std::string(pMsg) << std::endl;

    return VK_FALSE;
}

VkResult CreateDebugReportCallbackEXT(
  VkInstance instance,
  const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
  const VkAllocationCallbacks* pAllocator,
  VkDebugReportCallbackEXT* pCallback) {
    auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pCallback);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr) {
        func(instance, callback, pAllocator);
    }
}

class HelloTriangleApplication
  : public Application
{
public:
  void run() {
    init_window(512, 512);
    init_vulkan();
    main_loop();
    cleanup();  
  }
private:
  void init_window(std::size_t width, std::size_t height)
  {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    _window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
  }

  void init_vulkan()
  {
    if(!checkValidationLayerSupport())
    {
      throw std::runtime_error("validation layer request, but not supported!");
    }

    //create application info
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle!";
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //create constructor info
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto glfwExtensions = getRequiredExtensions();
    createInfo.enabledExtensionCount = glfwExtensions.size();
    createInfo.ppEnabledExtensionNames = glfwExtensions.data();

    if(!validationLayers.empty()) {
      createInfo.enabledLayerCount = validationLayers.size();
      createInfo.ppEnabledLayerNames = validationLayers.data();
    } else {
      createInfo.enabledLayerCount = 0;
    }

    //create instance!
    VkResult result = vkCreateInstance(&createInfo, nullptr, &_instance);
    if(result != VK_SUCCESS)
    {
      throw std::runtime_error("failed to create instance(" + std::to_string(result) + ")");
    }

    uint32_t vulkanExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &vulkanExtensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(vulkanExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &vulkanExtensionCount, extensions.data());

    std::cout << "available extensions:\n";
    for(const auto& extension : extensions)
    {
      std::cout << "\t" << extension.extensionName << "\n";
    }

    //setup debug callback
    if(!validationLayers.empty())
    {
      VkDebugReportCallbackCreateInfoEXT debugCallbackCreateInfo = {};
      debugCallbackCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
      debugCallbackCreateInfo.pNext = nullptr;
      debugCallbackCreateInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
      debugCallbackCreateInfo.pfnCallback = debugCallback;
      debugCallbackCreateInfo.pUserData = nullptr;

      if(CreateDebugReportCallbackEXT(_instance, &debugCallbackCreateInfo, nullptr, &_debugCallback) != VK_SUCCESS)
      {
        throw std::runtime_error("debug callback setup failed");
      }
    }

    create_surface();

    pick_physical_device();
    create_logical_device();
  }

  void create_surface() {
    if(glfwCreateWindowSurface(_instance, _window, nullptr, &_surface) != VK_SUCCESS) {
      throw std::runtime_error("failed to create window surface!");
    }
  }

  void pick_physical_device()
  {
    _physicalDevice = VK_NULL_HANDLE;
    uint32_t device_count = 0;
    vkEnumeratePhysicalDevices(_instance, &device_count, nullptr);
    if(device_count == 0) {
      throw std::runtime_error("failed to find GPUs with vulkan support");
    }
    std::vector<VkPhysicalDevice> devices(device_count);
    vkEnumeratePhysicalDevices(_instance, &device_count, devices.data());

    for(const auto& device : devices) {
      if(isDeviceSuitable(device)) {
        _physicalDevice = device;
        break;
      }
    }
    if(_physicalDevice == VK_NULL_HANDLE) {
      throw std::runtime_error("failed to find suitable GPU!");
    }
  }

  struct QueueFamilyIndices
  {
    int32_t graphicsFamily = -1;
    int32_t presentFamily = -1;
    bool isComplete() {
      return graphicsFamily >= 0 && presentFamily >= 0;
    }
  };

  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device)
  {
    QueueFamilyIndices indices;
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int32_t index = 0;
    for(const auto& queueFamily : queueFamilies) {
      if(queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
        indices.graphicsFamily = index;
      }
      VkBool32 presentSupport = false;
      vkGetPhysicalDeviceSurfaceSupportKHR(device, index, _surface, &presentSupport);
      if(queueFamily.queueCount > 0 && presentSupport) {
        indices.presentFamily = index;
      }
      if(indices.isComplete()) {
        break;
      } else {
        ++index;
      }
    }

    return indices;
  }

  bool isDeviceSuitable(VkPhysicalDevice device)
  {
    VkPhysicalDeviceProperties device_properties;
    VkPhysicalDeviceFeatures device_features;
    vkGetPhysicalDeviceProperties(device, &device_properties);
    vkGetPhysicalDeviceFeatures(device, &device_features);

    QueueFamilyIndices indices = findQueueFamilies(device);

    return  indices.isComplete() && checkDeviceExtensionSupport(device);
  }

  bool checkDeviceExtensionSupport(VkPhysicalDevice physicalDevice)
  {
    uint32_t extension_count = 0;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extension_count, nullptr);
    std::vector<VkExtensionProperties> availableExtensions(extension_count);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extension_count, availableExtensions.data());
    std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());
    for(const auto& extension : availableExtensions) {
      requiredExtensions.erase(extension.extensionName);
    }
    return requiredExtensions.empty();
  }

  void create_logical_device()
  {
    QueueFamilyIndices indices = findQueueFamilies(_physicalDevice);
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<int32_t> uniqueQueueFamilies = {indices.graphicsFamily, indices.presentFamily};

    for(int32_t queueFamily : uniqueQueueFamilies) {
      VkDeviceQueueCreateInfo queueCreateInfo = {};
      queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      queueCreateInfo.queueFamilyIndex = indices.graphicsFamily;
      queueCreateInfo.queueCount = 1;
      queueCreateInfo.pQueuePriorities = &QUEUE_PRIORITY;
      queueCreateInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures = {};

    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pQueueCreateInfos = queueCreateInfos.data();
    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
    createInfo.ppEnabledExtensionNames = deviceExtensions.data();

    if(validationLayers.size()) {
      createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
      createInfo.ppEnabledLayerNames = validationLayers.data();
    } else {
      createInfo.enabledLayerCount = 0;
    }

    if(vkCreateDevice(_physicalDevice, &createInfo, nullptr, &_device) != VK_SUCCESS) {
      throw std::runtime_error("failed to create logical device!");
    }

    vkGetDeviceQueue(_device, indices.graphicsFamily, 0, &_graphicsQueue);
  }

  void main_loop()
  {
    while(!glfwWindowShouldClose(_window))
    {
      glfwPollEvents();
    }
  }

  void cleanup() {
    if(_instance) {
      if(_debugCallback) {
        DestroyDebugReportCallbackEXT(_instance, _debugCallback, nullptr);
      }
      if(_surface) {
        vkDestroySurfaceKHR(_instance, _surface, nullptr);
      }
      vkDestroyInstance(_instance, nullptr);
    }
    if(_device) {
      vkDestroyDevice(_device, nullptr);
    }
    if(_window)
    {
      glfwDestroyWindow(_window);
    }
    glfwTerminate();
  }

private:
  float QUEUE_PRIORITY = 1.0f;
private:
  GLFWwindow * _window;
  VkInstance _instance;
  VkPhysicalDevice _physicalDevice;
  VkDevice _device;
  VkQueue _graphicsQueue;
  VkDebugReportCallbackEXT _debugCallback;
  VkSurfaceKHR _surface;
  VkQueue presentQueue;
};

int main(int argc, char * argv[])
{
  std::unique_ptr<Application> app = std::make_unique<HelloTriangleApplication>(); 
  try
  {
    app->run();
  }
  catch(std::runtime_error &ex)
  {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
