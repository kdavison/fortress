#yaml-cpp
set(YAML_CPP_BUILD_TOOLS OFF)
add_subdirectory(yaml-cpp)
#entityx
set(ENTITYX_BUILD_TESTING false)
set(ENTITYX_BUILD_SHARED false)
add_subdirectory(entityx)
#set_property(DIRECTORY yaml-cpp APPEND PROPERTY VARIABLES "YAML_CPP_BUILD_TOOLS=NO")
