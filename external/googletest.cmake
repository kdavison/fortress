cmake_minimum_required (VERSION 3.5)
include(ExternalProject)

set(GOOGLETEST_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_googletest
  CMAKE_ARGS "${GOOGLETEST_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND $(MAKE) install
)

## outputs
add_library(gmock STATIC IMPORTED)
add_library(gtest STATIC IMPORTED)
add_library(gmock_main STATIC IMPORTED)
add_library(gtest_main STATIC IMPORTED)

## where?
set_property(TARGET gmock PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgmock.a)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgtest.a)
set_property(TARGET gmock_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgmock_main.a)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgtest_main.a)

## Chain together so everything gets built!
add_dependencies(gmock gmock_main)
add_dependencies(gtest gtest_main)
add_dependencies(gmock_main project_googletest)
add_dependencies(gtest_main project_googletest)

