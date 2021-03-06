cmake_minimum_required(VERSION 3.5)

add_custom_target(
  project_vulkan ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/external/VulkanSDK/1.0.51.0/x86_64 ${ARTIFACT_DIRECTORY}
  COMMENT "installing vulkan SDK..."
)

add_definitions(
  -DVULKAN_SDK=${ARTIFACT_DIRECTORY}
  -DVK_LAYER_PATH="${ARTIFACT_DIRECTORY}/etc/explicit_layer.d"
)
