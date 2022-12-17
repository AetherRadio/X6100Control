#!/bin/sh

source ./conf.sh

PATH=${BUILDROOT}/build/host/bin:${PATH}

cmake \
    .. \
    -G"Unix Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE=${BUILDROOT}/build/host/share/buildroot/toolchainfile.cmake \
    -DCMAKE_INSTALL_PREFIX="/usr" \
    -DCMAKE_INSTALL_RUNSTATEDIR="/run" \
    -DCMAKE_COLOR_MAKEFILE=OFF \
    -DBUILD_DOC=OFF \
    -DBUILD_DOCS=OFF \
    -DBUILD_EXAMPLE=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_TEST=OFF \
    -DBUILD_TESTS=OFF \
    -DBUILD_TESTING=OFF \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_SHARED_LIB=ON
