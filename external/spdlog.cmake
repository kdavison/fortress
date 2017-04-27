cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(SPEED_LOG_OPTIONS
  -DSPDLOG_BUILD_TESTING=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY} 
)
ExternalProject_Add(
  project_spdlog
  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
)

add_library(spdlog INTERFACE IMPORTED)
add_dependencies(spdlog project_spdlog)

