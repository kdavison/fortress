cmake_minimum_required (VERSION 3.5)

##
## Setup RPATH stuff
##
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_INSTALL_RPATH ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(SOURCE
  main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE})
add_dependencies(${PROJECT_NAME}
  project_spdlog
  project_glfw
  project_glm
  project_vulkan
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

link_directories(
  ${ARTIFACT_DIRECTORY}/lib
  ${ARTIFACT_DIRECTORY}/shared  
)
target_link_libraries(${PROJECT_NAME}
  ${ARTIFACT_DIRECTORY}/lib/libglfw3.a
  ${ARTIFACT_DIRECTORY}/lib/libvulkan.so
  X11
  Xcursor
  Xrandr
  Xi
  Xinerama
  Xxf86vm
  GL
  dl
  ${LIBRARY_PTHREAD}
)
