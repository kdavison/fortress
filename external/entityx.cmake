cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

set(ENTITY_X_OPTIONS
    -DENTITYX_BUILD_TESTING=OFF
    -DENTITYX_BUILD_SHARED=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_entityx
  CMAKE_ARGS "${ENTITY_X_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/entityx"
)

add_library(entityx STATIC IMPORTED)
set_property(TARGET entityx PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libentityx.a)
add_dependencies(entityx project_entityx)
