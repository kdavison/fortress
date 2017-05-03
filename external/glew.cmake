cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(GLEW_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_glew
  CMAKE_ARGS "${GLEW_CMAKE_OPTIONS}"
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glew
  CONFIGURE_COMMAND ""
  BUILD_COMMAND cd auto COMMAND $(MAKE) COMMAND cd - COMMAND $(MAKE)
  BUILD_IN_SOURCE 1
  INSTALL_COMMAND $(MAKE) install DESTDIR=${ARTIFACT_DIRECTORY}
)

add_library(glew SHARED IMPORTED)
set_property(TARGET glew PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libglew.so)
add_dependencies(glew project_glew)
