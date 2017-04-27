cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(YAML_OPTIONS
    -DYAML_CPP_BUILD_TOOLS=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_yamlcpp
  CMAKE_ARGS "${YAML_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/yaml-cpp"
)

add_library(yaml-cpp STATIC IMPORTED)
set_property(TARGET yaml-cpp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libyaml-cpp.a)
add_dependencies(yaml-cpp project_yamlcpp)
