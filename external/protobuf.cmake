cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(PROTOBUF_CMAKE_OPTIONS
  -Dprotobuf_BUILD_TESTS=OFF
  -Dprotobuf_BUILD_EXAMPLES=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_protobuf
  CMAKE_ARGS "${PROTOBUF_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/protobuf"
  CONFIGURE_COMMAND ./autogen.sh COMMAND ./configure --disable-shared --prefix=${ARTIFACT_DIRECTORY}
  BUILD_COMMAND $(MAKE) clean COMMAND $(MAKE)
  BUILD_IN_SOURCE 1
  TEST_BEFORE_INSTALL 1
  TEST_COMMAND $(MAKE) check
)

add_library(protobuf SHARED IMPORTED)
set_property(TARGET protobuf PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libprotobuf.so)
add_dependencies(protobuf project_protobuf)
