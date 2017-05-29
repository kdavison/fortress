cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(GLEW_CMAKE_OPTIONS
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_glew
  CMAKE_ARGS "${GLEW_CMAKE_OPTIONS}"
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glew/build/cmake
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)
