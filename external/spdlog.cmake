cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#set(SPEED_LOG_OPTIONS
#  -DSPDLOG_BUILD_TESTING=OFF
#  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
#)

#ExternalProject_Add(
#  project_spdlog
#  PREFIX spdlog
#  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
#  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
#  INSTALL_DIR ${ARTIFACT_DIRECTORY}
#)

set(SPDLOG_BUILD_TESTING OFF)
add_subdirectory(external/spdlog)
