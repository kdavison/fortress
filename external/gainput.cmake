cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(GAINPUT_CMAKE_OPTIONS
  -DGAINPUT_SAMPLES=OFF
  -DGAINPUT_TESTS=OFF
  -DGAINPUT_BUILD_SHARED=OFF
  -DGAINPUT_LIB_BUILD=ON
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_gainput
  CMAKE_ARGS "${GAINPUT_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/gainput"
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)
