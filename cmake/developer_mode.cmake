# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Aether Xiegu X6100 Control
#
# Copyright (c) 2022 Rui Oliveira aka CT7ALW

include_guard(GLOBAL)

if(NOT AETHER_X6100CTRL_DEVELOPER_MODE)
  return()
endif()

if(NOT PROJECT_IS_TOP_LEVEL)
  message(AUTHOR_WARNING "Developer mode is intended for developers of ${PROJECT_NAME}. Ignoring.")
  return()
endif()

# Developer mode define
add_compile_definitions(AETHER_X6100CTRL_DEVELOPER_MODE)

# Diagnostic flags
if(MSVC)
  set(DIAGNOSTIC_FLAGS "/W4")
else()
  set(DIAGNOSTIC_FLAGS "-Wall" "-Wextra" "-pedantic" "-Wconversion" "-Wsign-conversion")
endif()

foreach(DIAGNOSTIC_FLAG ${DIAGNOSTIC_FLAGS})
  check_c_compiler_flag(${DIAGNOSTIC_FLAG} AETHER_X6100CTRL_HAS_C_${DIAGNOSTIC_FLAG})
  if(AETHER_X6100CTRL_HAS_C_${DIAGNOSTIC_FLAG})
    add_compile_options($<$<COMPILE_LANGUAGE:C>:${DIAGNOSTIC_FLAG}>)
  endif()
  check_cxx_compiler_flag(${DIAGNOSTIC_FLAG} AETHER_X6100CTRL_HAS_CXX_${DIAGNOSTIC_FLAG})
  if(AETHER_X6100CTRL_HAS_CXX_${DIAGNOSTIC_FLAG})
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${DIAGNOSTIC_FLAG}>)
  endif()
endforeach()

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy the compilation database to the project folder to help with clangd
# Only Make and Ninja (non-multi) are supported to export a compilation
# database.
if((${CMAKE_GENERATOR} MATCHES "Make") OR (${CMAKE_GENERATOR} MATCHES "Ninja$"))
  add_custom_target(
    "aether-x6100ctrl-ccc" ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    VERBATIM)
endif()

# Testing
include(CTest)
