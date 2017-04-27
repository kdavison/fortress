cmake_minimum_required (VERSION 3.5)
project(fortress)

## VERSIONING
set(${PROJECT_NAME}_VERSION_MAJOR "0")
set(${PROJECT_NAME}_VERSION_MINOR "0")
set(${PROJECT_NAME}_VERSION_PATCH "0")
set(${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}")
add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")
add_definitions(-DPROJECT_VERSION="${${PROJECT_NAME}_VERSION}")

## OUTPUT PATHS
set(ARTIFACT_DIRECTORY ${CMAKE_SOURCE_DIR}/artifact)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/bin)

## MINIMUM C++ VERSION
set (CMAKE_CXX_STANDARD 14)

## THREADING PACKAGE
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set(COMPILE_PTHREAD "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  set(LIBRARY_PTHREAD ${CMAKE_THREAD_LIBS_INIT})
endif()

## project name and version
message(STATUS "=== ${PROJECT_NAME} - ${${PROJECT_NAME}_VERSION} ===")
#set library paths!
set(CMAKE_INSTALL_RPATH "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

## SHOULD WE BUILD THE TEST LIBRARY?!
option(FORTRESS_TEST "build tests" ON)

#include all the stuff in external/*
file(GLOB EXTERNAL_PROJECTS
  "external/*.cmake"
)
message(STATUS "including external projects:")
foreach(project ${EXTERNAL_PROJECTS})
  message(STATUS "    ${project}")
  include(${project})
endforeach(project)

add_subdirectory(source)
add_subdirectory(test)
