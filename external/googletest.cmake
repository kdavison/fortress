cmake_minimum_required (VERSION 3.5)
include(ExternalProject)

set(GOOGLETEST_OPTIONS
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_googletest
  CMAKE_ARGS "${GOOGLETEST_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)
