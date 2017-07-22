cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#set(INTRINSIC_OPTIONS
#  -DVK_SDK_PATH=${ARTIFACT_DIRECTORY}/vulkan
#  -DINTR_BUILD_STANDALONE_APP=OFF
#  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
#)

#ExternalProject_Add(
#  project_intrinsic
#  DEPENDS project_vulkan
#  CMAKE_ARGS "${INTRINSIC_OPTIONS}"
#  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/Intrinsic"
#  INSTALL_DIR ${ARTIFACT_DIRECTORY}
#)

add_subdirectory(external/Intrinsic)
