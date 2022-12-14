add_library(aether_radio::x6100_control ALIAS aether_x6100_control)

target_include_directories(aether_x6100_control #
                           PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS aether_x6100_control)

# The `CMAKE_CURRENT_[BINARY|SOURCE]_DIR` variables work because this file is `include`'d from the
# main CMakeLists.txt
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${AETHER_INCLUDE_DIR}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${AETHER_INCLUDE_DIR}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
