## include cmake moduels
include(ExternalProject)

## GOOGLE TEST
set(GOOGLETEST_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_googletest
  CMAKE_ARGS "${GOOGLETEST_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND $(MAKE) install
)
set_property(TARGET gmock PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgmock.a)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgtest.a)
set_property(TARGET gmock_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgmock_main.a)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgtest_main.a)
add_dependencies(gmock gmock_main)
add_dependencies(gtest gtest_main)
add_dependencies(gmock_main project_googletest)
add_dependencies(gtest_main project_googletest)

## YAML-CPP
set(YAML_OPTIONS
    -DYAML_CPP_BUILD_TOOLS=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_yamlcpp
  CMAKE_ARGS "${YAML_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/yaml-cpp"
)
set_property(TARGET yaml-cpp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libyaml-cpp.a)
add_dependencies(yaml-cpp external_yamlcpp)

## ENTITY-X
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
set_property(TARGET entityx PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libentityx.a)
add_dependencies(entityx project_entityx)

## SPEED LOG (spdlog)
set(SPEED_LOG_OPTIONS
  -DSPDLOG_BUILD_TESTING=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY} 
)
ExternalProject_Add(
  project_spdlog
  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
)
add_custom_target(spdlog)
add_dependencies(spdlog project_spdlog)

## PROTOBUF
set(PROTOBUF_CMAKE_OPTIONS
  -Dprotobuf_BUILD_TESTS=OFF
  -Dprotobuf_BUILD_EXAMPLES=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_protobuf
  CMAKE_ARGS "${PROTOBUF_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/protobuf"
  CONFIGURE_COMMAND ./autogen.sh COMMAND ./configure --disable-shared --prefix=${ARTIFACT_DIRECTORY}
  BUILD_COMMAND $(MAKE) clean COMMAND $(MAKE)
  BUILD_IN_SOURCE 1
  TEST_BEFORE_INSTALL 1
  TEST_COMMAND $(MAKE) check
)

set_property(TARGET protobuf PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libprotobuf.so)
add_dependencies(protobuf project_protobuf)

## GAINPUT
set(GAINPUT_CMAKE_OPTIONS
  -DGAINPUT_SAMPLES=OFF
  -DGAINPUT_TESTS=OFF
  -DGAINPUT_BUILD_SHARED=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_gainput
  CMAKE_ARGS "${GAINPUT_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/gainput"
)
set_property(TARGET gainput PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgainputstatic.a)
add_dependencies(gainput project_gainput)

## SDL 2.0
set(SDL2_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_sdl2
  URL https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
  CMAKE_ARGS "${SDL2_CMAKE_OPTIONS}"
  CONFIGURE_COMMAND ./configure --prefix=${ARTIFACT_DIRECTORY}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/SDL2-2.0.5"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)
set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2.a)
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2main.a)
add_dependencies(SDL2 SDL2main)
add_dependencies(SDL2main project_sdl2)

## SDL2pp SDL2 Wrapper
set(SDL2PP_CMAKE_OPTIONS
  -DSDL2PP_WITH_IMAGE=OFF
  -DSDL2PP_WITH_MIXER=OFF
  -DSDL2PP_WITH_TTF=OFF
  -DSDL2PP_WITH_EXAMPLES=OFF
  -DSDL2PP_WITH_TESTS=OFF
  -DSDL2PP_ENABLE_LIVE_TESTS=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  project_sdl2pp
  CMAKE_ARGS "${SDL2PP_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/libSDL2pp"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)
set_property(TARGET SDL2pp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libSDL2pp.so)
add_dependencies(SDL2pp project_sdl2 project_sdl2pp)


