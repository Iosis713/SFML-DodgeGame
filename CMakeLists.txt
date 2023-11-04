cmake_minimum_required(VERSION 3.10)
project(DodgeGame)

set (FLAGS -Wall -Wextra -Wpedantic -Werror)
set (SFML_LIB sfml-graphics
              sfml-window
              sfml-system)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIB})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})


set_target_properties(${PROJECT_NAME} PROPERTIES
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)

