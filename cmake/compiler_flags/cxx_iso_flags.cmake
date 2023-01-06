# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Aether Xiegu X6100 Control
#
# Copyright (c) 2022 Rui Oliveira aka CT7ALW

include_guard(GLOBAL)

if(NOT AETHER_X6100CTRL_USE_ISO_FLAGS)
  return()
endif()

set(ISO_FLAGS "/EHsc" "/volatile:iso" "/Zc:preprocessor" "/Zc:throwingNew" "/Zc:externConstexpr")

foreach(ISO_FLAG ${ISO_FLAGS})
  check_cxx_compiler_flag(${ISO_FLAG} HAS_CXX_${ISO_FLAG})
  if(HAS_CXX_${ISO_FLAG})
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${ISO_FLAG}>)
  endif()
endforeach()
