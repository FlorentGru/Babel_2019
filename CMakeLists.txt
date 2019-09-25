cmake_minimum_required(VERSION 3.5)
project(Babel LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Babel
main.cpp
)