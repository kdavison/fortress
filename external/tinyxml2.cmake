cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(TINYXML2_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_tinyxml2
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/tinyxml2"
  CMAKE_ARGS ${TINYXML2_CMAKE_OPTIONS}
  INSTALL_COMMAND $(MAKE) install  
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)
