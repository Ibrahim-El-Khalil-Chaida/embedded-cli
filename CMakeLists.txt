cmake_minimum_required(VERSION 3.10)
project(embedded-cli VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(cli_lib src/CLI.cpp)
add_executable(cli_app src/main.cpp)
target_link_libraries(cli_app PRIVATE cli_lib)