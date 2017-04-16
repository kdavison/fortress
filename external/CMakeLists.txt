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
ExternalProject_Add( spdlog
  CMAKE_ARGS "${SPEED_LOG_OPTIONS}"
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog"
)

ExternalProject_Add_Step(
  spdlog install
  DEPENDEES install
)

