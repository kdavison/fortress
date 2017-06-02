cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

ExternalProject_Add(
  project_sdl2_image
  HG_REPOSITORY http://hg.libsdl.org/SDL_image
  CONFIGURE_COMMAND ./autogen.sh && ./configure --prefix=${ARTIFACT_DIRECTORY} --disable-static
  BUILD_COMMAND $(MAKE)
  BUILD_IN_SOURCE 1
  INSTALL_COMMAND $(MAKE) install  
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)

add_dependencies(project_sdl2_image project_sdl2)
