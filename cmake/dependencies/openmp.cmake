#  SPDX-License-Identifier: LGPL-2.1-or-later
#
#  Aether Xiegu X6100 Control
#
#  Copyright (c) 2022 Rui Oliveira aka CT7ALW

include_guard(GLOBAL)

set(OPENMP_MSVC_EXPERIMENTAL_FLAG "/openmp:experimental")
if(MSVC)
  check_cxx_compiler_flag(${OPENMP_MSVC_EXPERIMENTAL_FLAG} HAS_OPENMP_EXPERIMENTAL)
  if(HAS_OPENMP_EXPERIMENTAL)
    set(OpenMP_CXX_FLAGS
        ${OPENMP_MSVC_EXPERIMENTAL_FLAG}
        CACHE STRING "OpenMP CXX flags" FORCE)
    set(OpenMP_CXX_LIB_NAMES
        ""
        CACHE STRING "OpenMP Lib names" FORCE)
  endif()
endif()

find_package(OpenMP)
