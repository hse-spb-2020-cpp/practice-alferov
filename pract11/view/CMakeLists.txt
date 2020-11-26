cmake_minimum_required(VERSION 3.10)
project(view)

include_directories(include)

add_executable(view_bar
    src/main.cpp
    src/view_bar.cpp
)

add_executable(view_baz
    src/main.cpp
    src/view_baz.cpp
)
