## include cmake moduels
include(ExternalProject)

## GOOGLE TEST
set(GOOGLETEST_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  googletest
  CMAKE_ARGS "${GOOGLETEST_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
)
ExternalProject_Add_Step(
  googletest install
  DEPENDEES install
)

## YAML-CPP
set(YAML_OPTIONS
    -DYAML_CPP_BUILD_TOOLS=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  yaml
  CMAKE_ARGS "${YAML_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/yaml-cpp"
)
ExternalProject_Add_Step(
  yaml install
  DEPENDEES install
)

## ENTITY-X
set(ENTITY_X_OPTIONS
    -DENTITYX_BUILD_TESTING=OFF
    -DENTITYX_BUILD_SHARED=OFF
    -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  EntityX
  CMAKE_ARGS "${ENTITY_X_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/entityx"
)
ExternalProject_Add_Step(
  EntityX install
  DEPENDEES install
)

## SPEED LOG (spdlog)
set(SPEED_LOG_OPTIONS
  -DSPDLOG_BUILD_TESTING=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY} 
)
ExternalProject_Add(
  spdlog
  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
)

ExternalProject_Add_Step(
  spdlog install
  DEPENDEES install
)

## PROTOBUF
set(PROTOBUF_CMAKE_OPTIONS
  -Dprotobuf_BUILD_TESTS=OFF
  -Dprotobuf_BUILD_EXAMPLES=OFF
  -DBUILD_SHARED=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  protobuf
  CMAKE_ARGS "${PROTOBUF_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/protobuf"
  CONFIGURE_COMMAND ./autogen.sh COMMAND ./configure --disable-shared --prefix=${ARTIFACT_DIRECTORY}
  BUILD_COMMAND $(MAKE) clean COMMAND $(MAKE) COMMAND $(MAKE) check
  BUILD_IN_SOURCE 1
)
ExternalProject_Add_Step(
  protobuf install
  DEPENDEES install
)

## GAINPUT
set(GAINPUT_CMAKE_OPTIONS
  -DGAINPUT_SAMPLES=OFF
  -DGAINPUT_TESTS=OFF
  -DGAINPUT_BUILD_SHARED=OFF
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  gainput
  CMAKE_ARGS "${GAINPUT_CMAKE_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/gainput"
)
ExternalProject_Add_Step(
  gainput install
  DEPENDEES install
)

## SDL
set(SDL_CMAKE_OPTIONS
  -DCMAKE_INSTALL_PREFIX=${ARTIFACT_DIRECTORY}
)
ExternalProject_Add(
  sdl
  URL https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
  CMAKE_ARGS "${SDL_CMAKE_OPTIONS}"
  CONFIGURE_COMMAND ./configure --prefix=${ARTIFACT_DIRECTORY}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/SDL2-2.0.5"
  BUILD_COMMAND ${MAKE}
  BUILD_IN_SOURCE 1
)
ExternalProject_Add_Step(
  sdl install
  DEPENDEES install
)


