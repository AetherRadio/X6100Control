#  SPDX-License-Identifier: LGPL-2.1-or-later
#
#  Aether Xiegu X6100 Control
#
#  Copyright (c) 2022 Rui Oliveira aka CT7ALW

include_guard(GLOBAL)

if(NOT AETHER_X6100CTRL_USE_FAST_MATH)
  return()
endif()

if(MSVC)
  set(FASTMATH_FLAG "/fp:fast")
else()
  set(FASTMATH_FLAG "-ffast-math")
endif()

check_c_compiler_flag(${FASTMATH_FLAG} AETHER_X6100CTRL_HAS_C_FAST_MATH)
if(AETHER_X6100CTRL_HAS_C_FAST_MATH)
  add_compile_options($<$<COMPILE_LANGUAGE:C>:${FASTMATH_FLAG}>)
endif()

check_cxx_compiler_flag(${FASTMATH_FLAG} AETHER_X6100CTRL_HAS_CXX_FAST_MATH)
if(AETHER_X6100CTRL_HAS_CXX_FAST_MATH)
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${FASTMATH_FLAG}>)
endif()
