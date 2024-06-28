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

project(error_handling C)
add_executable(error_handling.bin error_handling.c)
if(UNIX)
  target_link_libraries(error_handling.bin editline)
endif()
target_include_directories(error_handling.bin PRIVATE deps/mpc)
target_sources(error_handling.bin PRIVATE deps/mpc/mpc.c)

project(s_expressions C)
add_executable(s_expressions.bin s_expressions.c)
if(UNIX)
  target_link_libraries(s_expressions.bin editline)
endif()
target_include_directories(s_expressions.bin PRIVATE deps/mpc)
target_sources(s_expressions.bin PRIVATE deps/mpc/mpc.c)

project(q_expressions C)
add_executable(q_expressions.bin q_expressions.c)
if(UNIX)
  target_link_libraries(q_expressions.bin editline)
endif()
target_include_directories(q_expressions.bin PRIVATE deps/mpc)
target_sources(q_expressions.bin PRIVATE deps/mpc/mpc.c)

project(variables C)
add_executable(variables.bin variables.c)
if(UNIX)
  target_link_libraries(variables.bin editline)
endif()
target_include_directories(variables.bin PRIVATE deps/mpc)
target_sources(variables.bin PRIVATE deps/mpc/mpc.c)

project(funtions C)
add_executable(funtions.bin funtions.c)
if(UNIX)
  target_link_libraries(funtions.bin editline)
endif()
target_include_directories(funtions.bin PRIVATE deps/mpc)
target_sources(funtions.bin PRIVATE deps/mpc/mpc.c)

if(PROJECT_IS_TOP_LEVEL AND UNIX)
  execute_process(
    COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
endif()
