cmake_minimum_required(VERSION 3.23)

project(
  AetherX6100ControlTest
  VERSION 0.1
  LANGUAGES C)

add_executable(x6100_atu atu.c)
add_executable(x6100_flow flow.c)
add_executable(x6100_ptt ptt.c)
add_executable(x6100_vfo vfo.c)

target_link_libraries(x6100_atu PRIVATE aether_x6100_control)
target_link_libraries(x6100_flow PRIVATE aether_x6100_control)
target_link_libraries(x6100_flow PRIVATE liquid)
target_link_libraries(x6100_ptt PRIVATE aether_x6100_control)
target_link_libraries(x6100_vfo PRIVATE aether_x6100_control)
