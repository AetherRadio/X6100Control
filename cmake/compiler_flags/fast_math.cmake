include_guard(GLOBAL)

if(NOT AETHERX6100CTRL_USE_FAST_MATH)
  return()
endif()

if(MSVC)
  set(FASTMATH_FLAG "/fp:fast")
else()
  set(FASTMATH_FLAG "-ffast-math")
endif()

check_c_compiler_flag(${FASTMATH_FLAG} AETHERX6100CTRL_HAS_C_FAST_MATH)
if(AETHERX6100CTRL_HAS_C_FAST_MATH)
  add_compile_options($<$<COMPILE_LANGUAGE:C>:${FASTMATH_FLAG}>)
endif()

check_cxx_compiler_flag(${FASTMATH_FLAG} AETHERX6100CTRL_HAS_CXX_FAST_MATH)
if(AETHERX6100CTRL_HAS_CXX_FAST_MATH)
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${FASTMATH_FLAG}>)
endif()
