#!/bin/sh

source ./conf.sh

PATH=${BUILDROOT}/host/bin:${PATH}

/usr/bin/make \
    DESTDIR=${BUILDROOT}/target \
    install/fast

/usr/bin/make \
    DESTDIR=${BUILDROOT}/host/arm-buildroot-linux-gnueabihf/sysroot \
    install/fast
