cmake_minimum_required (VERSION 3.5)

set(SOURCE
  main.cc
##platform
  platform/platformEvent.cc
##input handling
##gui
##renderer
)

add_executable(${PROJECT_NAME} ${SOURCE})
add_dependencies(${PROJECT_NAME}
  spdlog
)

target_compile_options(
  ${PROJECT_NAME} PUBLIC
  ${COMPILE_PTHREAD}
)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(INCLUDE_DIRECTORIES ${ARTIFACT_DIRECTORY}/include)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${ARTIFACT_DIRECTORY}/include
  ${INCLUDE_DIRECTORIES}
)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
set(CMAKE_INSTALL_RPATH "${ARTIFACT_DIRECTORY}/lib")

target_link_libraries(
  ${PROJECT_NAME} PUBLIC
  gainput
  CEGUICoreWindowRendererSet
  CEGUIExpatParser
  CEGUIBase-0
  CEGUICommonDialogs-0
  CEGUIOpenGLRenderer-0
  SDL2
  SDL2main
  dl
  X11
  libGL.so
  ${LIBRARY_PTHREAD}
)
