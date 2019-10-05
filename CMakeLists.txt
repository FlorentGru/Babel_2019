cmake_minimum_required(VERSION 3.5)
project(babel LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
if (UNIX)
    add_definitions("-fPIC -Wall -Wextra -Wshadow -Wuninitialized -Wunreachable-code")
endif (UNIX)

include(CTest)
enable_testing()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


include(build/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Boost COMPONENTS filesystem unit_test_framework REQUIRED)

include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SOURCE_SERVER "src/server/*.cpp" "includes/server/*.hpp")
include_directories(includes/server cmake)
file(GLOB_RECURSE SOURCE_CLIENT "src/GUI/*.cpp" "src/client/*.cpp" "includes/GUI/*.hpp" "includes/client/*.hpp")
include_directories(includes/client includes/GUI cmake)

# add_executable(babel_client ${SOURCE_CLIENT})
# target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Network)

add_executable(babel_server ${SOURCE_SERVER})
target_link_libraries(babel_server ${CONAN_LIBS} Qt5::Widgets Qt5::Network)

add_executable(babel_client ${SOURCE_CLIENT})
target_link_libraries(babel_client ${CONAN_LIBS}  Qt5::Widgets Qt5::Network Qt5::Gui)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf [Paths]\nPrefix = ${CONAN_QT_ROOT})
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf ${CONAN_QT_ROOT})