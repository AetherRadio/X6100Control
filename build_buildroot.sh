# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Aether Xiegu X6100 Control
#
# SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BUILDROOT_DIR="${SCRIPT_DIR}/../X6100Buildroot/build"

cmake --preset=buildroot

cd build/buildroot
make

make DESTDIR=${BUILDROOT_DIR}/target install
make DESTDIR=${BUILDROOT_DIR}/host/arm-buildroot-linux-gnueabihf/sysroot install
