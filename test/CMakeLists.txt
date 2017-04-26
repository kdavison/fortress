cmake_minimum_required (VERSION 3.5)

set(PROJECT_TEST ${PROJECT_NAME}.test)

set(SOURCE
  ${SOURCE}
  main.cxx
)

add_executable(${PROJECT_TEST} ${SOURCE})

get_property(test TARGET gmock PROPERTY IMPORTED_LOCATION)
message(STATUS ${test})

target_compile_options(
  ${PROJECT_TEST} PUBLIC
  ${COMPILE_PTHREAD}
)

target_include_directories(
  ${PROJECT_TEST} PUBLIC
  ${ARTIFACT_DIRECTORY}/include
)

link_directories(${CMAKE_SOURCE_DIR}/artifact/lib)
target_link_libraries(
  ${PROJECT_TEST}
  gmock
  gtest
  gmock_main
  gtest_main
  ${LIBRARY_PTHREAD}
)
