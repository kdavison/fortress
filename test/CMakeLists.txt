cmake_minimum_required (VERSION 3.5)

project(${PROJECT_NAME}.test)

set(SOURCE
  ${SOURCE}
  main.cxx
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_options(
  ${PROJECT_NAME} PUBLIC
  ${COMPILE_PTHREAD}
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${ARTIFACT_DIRECTORY}/include
)

link_directories(${CMAKE_SOURCE_DIR}/artifact/lib)
target_link_libraries(
  ${PROJECT_NAME}
  gmock
  gtest
  gmock_main
  gtest_main
  ${LIBRARY_PTHREAD}
)
