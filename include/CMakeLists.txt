# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Aether Xiegu X6100 Control
#
# Copyright (c) 2022 Rui Oliveira aka CT7ALW

target_sources(aether_x6100_control PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(aether_radio)
