cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(pqasm)

set(FLAGS -Wall -Wextra -Werror -pedantic -pedantic-errors -g)

add_compile_options(${FLAGS})

#enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)