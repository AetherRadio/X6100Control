add_library(aether_radio::x6100_control ALIAS aether_x6100_control)

target_include_directories(aether_x6100_control #
                           PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS aether_x6100_control)

install(TARGETS aether_x6100_control FILE_SET HEADERS)
