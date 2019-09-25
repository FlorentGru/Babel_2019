cmake_minimum_required(VERSION 3.5)
project(Babel LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "includes/*.hpp")
include_directories(includes cmake)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

add_executable(Babel
${SOURCE_FILES}
)

target_link_libraries(Babel PRIVATE Qt5::Widgets)
target_link_libraries(Babel PRIVATE Qt5::Network)