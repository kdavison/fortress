#!/bin/bash

BUILD_PREFIX=build
BUILD=$(find * -type d -name "${BUILD_PREFIX}.*")
if [ -z "${BUILD}" ]
then
BUILD=$(mktemp -d --tmpdir=$(pwd) -t ${BUILD_PREFIX}.XXXXXXXX)
else
BUILD=$(pwd)/${BUILD}
fi

cd ${BUILD}
cmake ../
make
