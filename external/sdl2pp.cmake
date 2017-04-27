cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(SDL2PP_CMAKE_OPTIONS
  -DSDL2PP_WITH_IMAGE=OFF
  -DSDL2PP_WITH_MIXER=OFF
  -DSDL2PP_WITH_TTF=OFF
  -DSDL2PP_WITH_EXAMPLES=OFF
  -DSDL2PP_WITH_TESTS=OFF
  -DSDL2PP_ENABLE_LIVE_TESTS=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_sdl2pp
  CMAKE_ARGS "${SDL2PP_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/libSDL2pp"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)

ExternalProject_Get_Property(project_sdl2 install_dir)
include_directories( ${install_dir}/include/SDL2pp )

set(CMAKE_INSTALL_RPATH "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library(SDL2pp STATIC IMPORTED)
set_property(TARGET SDL2pp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2pp.so)
add_dependencies(SDL2pp project_sdl2pp)
add_dependencies(project_sdl2pp SDL2)
