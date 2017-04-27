cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(GAINPUT_CMAKE_OPTIONS
  -DGAINPUT_SAMPLES=OFF
  -DGAINPUT_TESTS=OFF
  -DGAINPUT_BUILD_SHARED=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_gainput
  CMAKE_ARGS "${GAINPUT_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/gainput"
)

add_library(gainput STATIC IMPORTED)
set_property(TARGET gainput PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgainputstatic.a)
add_dependencies(gainput project_gainput)

