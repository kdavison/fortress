cmake_minimum_required (VERSION 3.5)

project(fortress.test)

set(SOURCE
  ${SOURCE}
  main.cxx
)

set(LIBS
  gmock
  gtest
  gmock_main
  gtest_main
)

add_executable(fortress.test ${SOURCE})

target_compile_options(
  fortress.test PUBLIC
  ${COMPILE_PTHREAD}
)

target_include_directories(
  fortress.test PUBLIC
  ${ARTIFACT_DIRECTORY}/include
)

find_library(LIBRARIES NAMES ${LIBS} PATHS ${ARTIFACT_DIRECTORY}/lib)
target_link_libraries(
  fortress.test
  ${LIBRARIES}
  ${LIBRARY_PTHREAD}
)
