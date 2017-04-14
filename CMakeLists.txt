cmake_minimum_required (VERSION 3.5)
project(FORTRESS)

set(FORTRESS_VERSION_MAJOR "0")
set(FORTRESS_VERSION_MINOR "0")
set(FORTRESS_VERSION_PATCH "0")
set(FORTRESS_VERSION "${FORTRESS_VERSION_MAJOR}.${FORTRESS_VERSION_MINOR}.${FORTRESS_VERSION_PATCH}")

set(EXTERNAL_LIBRARY_PREFIX ${CMAKE_SOURCE_DIR}/artifact)

set (CMAKE_CXX_STANDARD 14)

option(FORTRESS_TEST "build tests" ON)


include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/source
  ${EXTERNAL_LIBRARY_PREFIX}/include}
)

link_directories(
  ${EXTERNAL_LIBRARY_PREFIX}/lib
)

add_subdirectory(${CMAKE_SOURCE_DIR}/external)
add_subdirectory(${CMAKE_SOURCE_DIR}/source)

if(GAMYGDALA_TEST)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()
