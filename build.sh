#!/bin/bash

BUILD=$(find * -type d -name "out.*")
if [ -z "${BUILD}" ]
then
BUILD=$(mktemp -d --tmpdir=$(pwd) -t out.XXXXXXXX)
else
BUILD=$(pwd)/${BUILD}
fi

cd ${BUILD}
cmake ../
make
