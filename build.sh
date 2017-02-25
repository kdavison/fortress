#!/bin/bash

BUILD=$(find * -type d -name "out.*")
if [ -z "${BUILD}" ]
then
BUILD=$(mktemp -d --tmpdir=$(pwd) -t out.XXXXXXXX)
else
BUILD=$(pwd)/${BUILD}
fi

cd ${BUILD}
cmake \
  -DYAML_CPP_BUILD_TOOLS:BOOL=OFF \
  -DENTITYX_BUILD_TESTING:BOOL=OFF \
  -DENTITYX_BUILD_SHARED:BOOL=OFF \
  ../
make
make install
