cmake_minimum_required (VERSION 3.5)
project(fortress)

##
# OPTIONS
##
option(FORTRESS_TEST "build tests" ON) #BUILD TEST LIBRARY?

##
# VERSIONING
##
set(${PROJECT_NAME}_VERSION_MAJOR "0")
set(${PROJECT_NAME}_VERSION_MINOR "0")
set(${PROJECT_NAME}_VERSION_PATCH "0")
set(${PROJECT_NAME}_VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH})
add_definitions(-DPROJECT_NAME=${PROJECT_NAME})
add_definitions(-DPROJECT_VERSION=${${PROJECT_NAME}_VERSION})
add_definitions(-DHOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME})

message("=== ${PROJECT_NAME} - ${${PROJECT_NAME}_VERSION} ===")

##
# CMAKE CONFIGURATION
##
set(CMAKE_CXX_STANDARD 14)
set(ARTIFACT_DIRECTORY ${CMAKE_SOURCE_DIR}/artifact)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ARTIFACT_DIRECTORY}/bin)
set(CMAKE_INSTALL_RPATH "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

##
# Find Threading Package
##
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set(COMPILE_PTHREAD "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  set(LIBRARY_PTHREAD ${CMAKE_THREAD_LIBS_INIT})
endif()

##
# Include External Projects
##
set(EXTERNAL_PROJECTS
  yaml-cpp
  spdlog
  sdl2
  glew
  cegui
  entityx
  googletest
  protobuf
)

message(STATUS "External Projects:")
foreach(project ${EXTERNAL_PROJECTS})
  message(STATUS "    ${project}")
  include(external/${project}.cmake)
endforeach(project)

##
# TARGETS
##
add_subdirectory(source)
#add_subdirectory(test)

