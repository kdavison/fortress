cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(SDL2_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_sdl2
  URL https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
  CMAKE_ARGS "${SDL2_CMAKE_OPTIONS}"
  CONFIGURE_COMMAND ./configure --prefix=${ARTIFACT_DIRECTORY}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/SDL2-2.0.5"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)

add_library(SDL2 STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2.a)
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2main.a)
add_dependencies(SDL2 SDL2main)
add_dependencies(SDL2main project_sdl2)
