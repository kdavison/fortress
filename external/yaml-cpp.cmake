cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#set(YAML_OPTIONS
#  -DYAML_CPP_BUILD_TOOLS=OFF
#  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
#)

#ExternalProject_Add(
#  project_yamlcpp
#  PREFIX yaml-cpp
#  CMAKE_ARGS "${YAML_OPTIONS}"
#  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/yaml-cpp"
#  INSTALL_DIR ${ARTIFACT_DIRECTORY}
#)

set(YAML_CPP_BUILD_TOOLS OFF)
add_subdirectory(external/yaml-cpp)
