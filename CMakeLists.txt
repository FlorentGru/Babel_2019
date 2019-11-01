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
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(build/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

include(CPack)
include_directories(includes/server includes/client includes/GUI)

add_executable(babel_server
    src/server/server.cpp
    includes/server/server.hpp
    src/server/session.cpp
    includes/server/session.hpp
    src/server/database.cpp
    includes/server/database.hpp
    src/client/packet.cpp
    includes/client/packet.hpp
)
target_link_libraries(babel_server ${CONAN_LIBS})

add_executable(babel_client
    src/client/AClientConnection.cpp
    includes/client/AClientConnection.hpp
    src/client/client_tcp.cpp
    includes/client/client_tcp.hpp
    src/client/client_udp.cpp
    includes/client/client_udp.hpp
    src/client/packet.cpp
    includes/client/packet.hpp
    src/GUI/add_contact.cpp
    includes/GUI/add_contact.hpp
    src/GUI/contactwindow.cpp
    includes/GUI/contactwindow.hpp
    src/GUI/login.cpp
    includes/GUI/login.hpp
    src/GUI/registration.cpp
    includes/GUI/registration.hpp
)
target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Network)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf "[Paths]\nPrefix = ")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/bin/qt.conf ${CONAN_QT_ROOT})