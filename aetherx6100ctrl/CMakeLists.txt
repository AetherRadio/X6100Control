if(NOT UNIX)
  message(FATAL_ERROR "${PROJECT_NAME} is not compatible with non-UNIX systems.")
endif()

add_library(aetherx6100ctrl)

set_target_properties(
  aetherx6100ctrl
  PROPERTIES EXPORT_NAME "aetherx6100ctrl" # -
             OUTPUT_NAME "aetherx6100ctrl" # -
             DEFINE_SYMBOL "AETHERX6100CTR_EXPORTING" # -
             VERSION "${PROJECT_VERSION}" # -
             SOVERSION "${PROJECT_VERSION_MAJOR}")

set(AETHERX6100CTR_EXPORT_HEADER_FILE "include/aether_x6100/control/api.h")

generate_export_header(
  aetherx6100ctrl
  BASE_NAME
  "AETHERX6100CTR"
  EXPORT_MACRO_NAME
  "AETHERX6100CTR_API"
  EXPORT_FILE_NAME
  ${AETHERX6100CTR_EXPORT_HEADER_FILE})

target_include_directories(aetherx6100ctrl
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)

target_sources(aetherx6100ctrl
               PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${AETHERX6100CTR_EXPORT_HEADER_FILE})

add_subdirectory(include)
add_subdirectory(src)

# Installation code
add_library(aetherx6100ctrl::aetherx6100ctrl ALIAS aetherx6100ctrl)

write_basic_package_version_file(aetherx6100ctrlConfigVersion.cmake COMPATIBILITY SameMajorVersion)
