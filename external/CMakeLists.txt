## include cmake moduels
include(ExternalProject)

## GOOGLE TEST
set(GOOGLETEST_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_googletest
  CMAKE_ARGS "${GOOGLETEST_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
)
#add_custom_target(trigger_googletest)
#add_dependencies(trigger_googletest external_googletest)
add_library(gmock STATIC IMPORTED)
add_library(gtest STATIC IMPORTED)
add_library(gmock_main STATIC IMPORTED)
add_library(gtest_main STATIC IMPORTED)
set_property(TARGET gmock PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set_property(TARGET gmock_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(gmock gmock_main)
add_dependencies(gtest gtest_main)
add_dependencies(gmock_main external_googletest)
add_dependencies(gtest_main external_googletest)

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
#add_custom_target(trigger_yamlcpp)
#add_dependencies(trigger_yamlcpp external_yamlcpp)
add_library(yaml-cpp STATIC IMPORTED)
set_property(TARGET yaml-cpp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(yaml-cpp external_yamlcpp)

## ENTITY-X
set(ENTITY_X_OPTIONS
    -DENTITYX_BUILD_TESTING=OFF
    -DENTITYX_BUILD_SHARED=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_entityx
  CMAKE_ARGS "${ENTITY_X_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/entityx"
)
#add_custom_target(trigger_entityx)
#add_dependencies(trigger_entityx external_entityx)
add_library(entityx STATIC IMPORTED)
set_property(TARGET entityx PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(entityx external_entityx)

## SPEED LOG (spdlog)
set(SPEED_LOG_OPTIONS
  -DSPDLOG_BUILD_TESTING=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY} 
)
ExternalProject_Add(
  external_spdlog
  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
)
add_custom_target(spdlog)
add_dependencies(spdlog external_spdlog)

## PROTOBUF
set(PROTOBUF_CMAKE_OPTIONS
  -Dprotobuf_BUILD_TESTS=OFF
  -Dprotobuf_BUILD_EXAMPLES=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_protobuf
  CMAKE_ARGS "${PROTOBUF_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/protobuf"
  CONFIGURE_COMMAND ./autogen.sh COMMAND ./configure --disable-shared --prefix=${ARTIFACT_DIRECTORY}
  BUILD_COMMAND $(MAKE) clean COMMAND $(MAKE)
  BUILD_IN_SOURCE 1
  TEST_BEFORE_INSTALL 1
  TEST_COMMAND $(MAKE) check
)
#add_custom_target(trigger_protobuf)
#add_dependencies(trigger_protobuf external_protobuf)
add_library(protobuf SHARED IMPORTED)
set_property(TARGET protobuf PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(protobuf external_protobuf)

## GAINPUT
set(GAINPUT_CMAKE_OPTIONS
  -DGAINPUT_SAMPLES=OFF
  -DGAINPUT_TESTS=OFF
  -DGAINPUT_BUILD_SHARED=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_gainput
  CMAKE_ARGS "${GAINPUT_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/gainput"
)
#add_custom_target(trigger_gainput)
#add_dependencies(trigger_gainput external_gainput)
add_library(gainputstatic STATIC IMPORTED)
set_property(TARGET gainputstatic PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(gainputstatic external_gainput)

## SDL 2.0
set(SDL2_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  external_sdl2
  URL https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
  CMAKE_ARGS "${SDL2_CMAKE_OPTIONS}"
  CONFIGURE_COMMAND ./configure --prefix=${ARTIFACT_DIRECTORY}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/SDL2-2.0.5"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)
#add_custom_target(trigger_sdl2)
#add_dependencies(trigger_sdl2 external_sdl2)
add_library(SDL2 STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(SDL2 SDL2main)
add_dependencies(SDL2main external_sdl2)

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
  external_sdl2pp
  CMAKE_ARGS "${SDL2PP_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/libSDL2pp"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)
#add_custom_target(trigger_sdl2pp)
#add_dependencies(trigger_sdl2pp trigger_sdl2 external_sdl2pp)
add_library(SDL2pp SHARED IMPORTED)
set_property(TARGET SDL2pp PROPERTY IMPORTED_LOCATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_dependencies(SDL2pp external_sdl2 external_sdl2pp)


