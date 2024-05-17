cmake_minimum_required(VERSION 3.12.0)

set(C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hello_world C)
add_executable(hello_world.bin hello_world.c)

project(prompt C)
add_executable(prompt.bin prompt.c)
if(UNIX)
  target_link_libraries(prompt.bin editline)
endif()

project(parsing C)
add_executable(parsing.bin parsing.c)
if(UNIX)
  target_link_libraries(parsing.bin editline)
endif()
target_include_directories(parsing.bin PRIVATE deps/mpc)
target_sources(parsing.bin PRIVATE deps/mpc/mpc.c)

project(evaluation C)
add_executable(evaluation.bin evaluation.c)
if(UNIX)
  target_link_libraries(evaluation.bin editline)
endif()
target_include_directories(evaluation.bin PRIVATE deps/mpc)
target_sources(evaluation.bin PRIVATE deps/mpc/mpc.c)

if(PROJECT_IS_TOP_LEVEL AND UNIX)
  execute_process(
    COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
endif()
