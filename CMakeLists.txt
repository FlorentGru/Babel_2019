cmake_minimum_required(VERSION 3.5)
project(Babel LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
file(GLOB_RECURSE SOURCE_CLIENT "src/client/*.cpp" "includes/client/*.hpp")
include_directories(includes/client cmake)
file(GLOB_RECURSE SOURCE_SERVER "src/server/*.cpp" "includes/server/*.hpp")
include_directories(includes/server cmake)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(babel_client ${SOURCE_CLIENT})
add_executable(babel_server ${SOURCE_SERVER})
target_link_libraries(babel_client ${CONAN_LIBS}  Qt5::Widgets Qt5::Network)
target_link_libraries(babel_server ${CONAN_LIBS}  Qt5::Widgets Qt5::Network)