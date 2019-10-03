cmake_minimum_required(VERSION 3.5)
project(Babel LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "includes/*.hpp")
include_directories(includes cmake)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(babel ${SOURCE_FILES})
target_link_libraries(babel ${CONAN_LIBS}  Qt5::Widgets Qt5::Network)