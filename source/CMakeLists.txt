cmake_minimum_required (VERSION 3.5)

set(SOURCE
  main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE})
add_dependencies(${PROJECT_NAME}
  project_spdlog
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

link_directories(${CMAKE_SOURCE_DIR}/artifact/lib)
target_link_libraries(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/artifact/lib/libCEGUICommonDialogs-0.so
  ${CMAKE_SOURCE_DIR}/artifact/lib/libCEGUIOpenGLRenderer-0.so
  ${CMAKE_SOURCE_DIR}/artifact/lib/libCEGUIBase-0.so
  ${CMAKE_SOURCE_DIR}/artifact/lib/libSDL2.so
  GL
  dl
  ${LIBRARY_PTHREAD}
)
