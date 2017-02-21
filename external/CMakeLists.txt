#yaml-cpp
set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "Build yaml-cpp tools")
add_subdirectory(yaml-cpp)

#set_property(DIRECTORY yaml-cpp APPEND PROPERTY VARIABLES "YAML_CPP_BUILD_TOOLS=NO")
