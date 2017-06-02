cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

ExternalProject_Add(
  project_silly
  HG_REPOSITORY https://bitbucket.org/cegui/silly
  CONFIGURE_COMMAND hg checkout v0-1 && ./bootstrap && ./configure --prefix=${ARTIFACT_DIRECTORY}
  BUILD_COMMAND $(MAKE)  
  BUILD_IN_SOURCE 1
  INSTALL_COMMAND $(MAKE) install
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)
