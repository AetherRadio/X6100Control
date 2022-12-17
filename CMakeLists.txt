cmake_minimum_required(VERSION 3.23)

project(
  AetherX6100Control
  VERSION 0.1
  LANGUAGES C CXX)

# Options ------------------------------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build libraries as shared libraries." ON) # CMake option name

option(AETHER_X6100CTRL_DEVELOPER_MODE "Enable developer helpers." OFF)

option(AETHER_X6100CTRL_USE_LTO "Enable link-time optimization when possible." ON)
option(AETHER_X6100CTRL_USE_FAST_MATH "Use fast math when possible (-ffast-math or /fp:fast)." OFF)

option(AETHER_X6100CTRL_SET_CXX_STANDARD "Set the C++ standard directly." ON)
option(AETHER_X6100CTRL_USE_CXX_ISO_FLAGS
       "Add extra compiler flags to make C++ compilers more compliant." ON)

# --------------------------------------------------------------------------------------------------

# Global variables
set(AETHER_VENDOR_NAME "AetherRadio")
set(AETHER_INCLUDE_DIR "include/aether_radio")

# Global modules
include(GenerateExportHeader)
include(CheckCXXCompilerFlag)

# Local modules
include(cmake/output_structure.cmake)
include(cmake/install_structure.cmake)
include(cmake/default_visibility.cmake)

include(cmake/compiler_flags/cxx_standard.cmake)
include(cmake/compiler_flags/fast_math.cmake)
include(cmake/compiler_flags/ipo_support.cmake)
include(cmake/compiler_flags/cxx_iso_flags.cmake)

include(cmake/dependencies/openmp.cmake)

include(cmake/developer_mode.cmake)

# Sanity checks
if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
else()
  message(FATAL_ERROR "${PROJECT_NAME} is not compatible with non-Linux systems.")
endif()

# Aether X6100 Control library
add_library(aether_x6100_control)
set_target_properties(
  aether_x6100_control
  PROPERTIES EXPORT_NAME "aether_x6100_control" #
             OUTPUT_NAME "aether_x6100_control" #
             DEFINE_SYMBOL "AETHER_X6100_CONTROL_EXPORTING" #
             VERSION "${PROJECT_VERSION}" #
             SOVERSION "${PROJECT_VERSION_MAJOR}")

# Export header
set(AETHER_X6100_CONTROL_EXPORT_HEADER_FILE "${AETHER_INCLUDE_DIR}/x6100_control/api.h")
generate_export_header(
  aether_x6100_control
  BASE_NAME
  "AETHER_X6100_CONTROL"
  EXPORT_MACRO_NAME
  "AETHER_X6100_CONTROL_API"
  EXPORT_FILE_NAME
  ${AETHER_X6100_CONTROL_EXPORT_HEADER_FILE})
target_sources(
  aether_x6100_control
  PUBLIC #
         FILE_SET HEADERS #
         BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/include)
target_sources(
  aether_x6100_control #
  PUBLIC #
         FILE_SET HEADERS #
         FILES ${CMAKE_CURRENT_BINARY_DIR}/${AETHER_X6100_CONTROL_EXPORT_HEADER_FILE})

# Code for the library
add_subdirectory(include)
add_subdirectory(src)

# Install and packaging code
include(cmake/installation.cmake)
include(cmake/packaging.cmake)
