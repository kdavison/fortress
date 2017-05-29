cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(CEGUI_CMAKE_OPTIONS
  -DCEGUI_BUILD_RENDERER_OPENGL3=ON
  -DCEGUI_USE_GLEW=TRUE
  -DCEGUI_USE_EPOXY=FALSE
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)

ExternalProject_Add(
  project_cegui
  URL http://prdownloads.sourceforge.net/crayzedsgui/cegui-0.8.7.zip
  CMAKE_ARGS "${CEGUI_CMAKE_OPTIONS}"
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/cegui-0.87
  INSTALL_DIR ${ARTIFACT_DIRECTORY}
)

add_dependencies(project_cegui project_sdl2 project_glew)
