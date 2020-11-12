cmake_minimum_required(VERSION 3.16)
project(calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2 -g")

add_executable(
    calculator
    src/calculator.cpp
    src/parser.cpp
    src/main.cpp
)
target_include_directories(calculator PUBLIC include/)
