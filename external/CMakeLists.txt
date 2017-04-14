## include cmake moduels
include(ExternalProject)

## GOOGLE TEST
ExternalProject_Add(
  googletest
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_LIBRARY_PREFIX}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/googletest"
)
ExternalProject_Add_Step(
  googletest install
  DEPENDEES install
)

## YAML-CPP
ExternalProject_Add(
  yaml
  CMAKE_ARGS -DYAML_CPP_BUILD_TOOLS=OFF -DCMAKE_INSTALL_PREFIX=${EXTERNAL_LIBRARY_PREFIX}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/yaml-cpp"
)
ExternalProject_Add_Step(
  yaml install
  DEPENDEES install
)

## ENTITY-X
ExternalProject_Add(
  EntityX
  CMAKE_ARGS -DENTITYX_BUILD_TESTING=OFF -DENTITYX_BUILD_SHARED=OFF -DCMAKE_INSTALL_PREFIX=${EXTERNAL_LIBRARY_PREFIX}
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/entityx"
)
ExternalProject_Add_Step(
  EntityX install
  DEPENDEES install
)
