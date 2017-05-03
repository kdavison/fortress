cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(CEGUI_CMAKE_OPTIONS
  -DCEGUI_BUILD_RENDERER_OPENGL3=ON
  -DCEGUI_USE_GLEW=TRUE
  -DCEGUI_USE_EPOXY=FALSE
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_cegui
  URL http://prdownloads.sourceforge.net/crayzedsgui/cegui-0.8.7.zip
  CMAKE_ARGS "${CEGUI_CMAKE_OPTIONS}"
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/cegui-0.87
  BUILD_COMMAND ${MAKE}
)

add_library(CEGUIBase-0 SHARED IMPORTED)
add_library(CEGUICommonDialogs-0 SHARED IMPORTED)
add_library(CEGUIOpenGLRenderer-0 SHARED IMPORTED)
add_library(CEGUICoreWindowRendererSet SHARED IMPORTED)
add_library(CEGUIExpatParser SHARED IMPORTED)

set_property(TARGET CEGUIBase-0 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libCEGUIBase-0.so)
set_property(TARGET CEGUICommonDialogs-0 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libCEGUICommonDialogs-0.so)
set_property(TARGET CEGUIOpenGLRenderer-0 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libCEGUIOpenGLRenderer-0.so)
set_property(TARGET CEGUICoreWindowRendererSet PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/cegui-0.8/libCEGUICoreWindowRendererSet.so)
set_property(TARGET CEGUIExpatParser PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/cegui-0.8/libCEGUIExpatParser.so)

add_dependencies(CEGUIBase-0 project_cegui)
add_dependencies(CEGUICommonDialogs-0 project_cegui)
add_dependencies(CEGUIOpenGLRenderer-0 project_cegui)

add_dependencies(project_cegui project_sdl2 project_glew)
