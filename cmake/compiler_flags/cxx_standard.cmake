# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Aether Xiegu X6100 Control
#
# SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>

include_guard(GLOBAL)

if(NOT AETHER_X6100CTRL_SET_CXX_STANDARD)
  return()
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)
