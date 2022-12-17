#!/bin/sh

source ./conf.sh

PATH=${BUILDROOT}/build/host/bin:${PATH}

/usr/bin/make \
    DESTDIR=${BUILDROOT}/build/target \
    install/fast
