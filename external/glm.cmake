cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(GLM_CMAKE_OPTIONS
  -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
  -DCMAKE_BUILD_TYPE=RELEASE
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_glm
  CMAKE_ARGS "${GLM_CMAKE_OPTIONS}"
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glm
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)