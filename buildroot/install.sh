#!/bin/sh

source ./conf.sh

PATH=${BUILDROOT}/build/host/bin:${PATH}

/usr/bin/make \
    DESTDIR=${BUILDROOT}/build/target \
    install/fast

/usr/bin/make \
    DESTDIR=${BUILDROOT}/build/host/arm-buildroot-linux-gnueabihf/sysroot \
    install/fast
