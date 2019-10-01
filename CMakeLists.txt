cmake_minimum_required(VERSION 3.5)
project(Babel VERSION 1.0)

include(CTest)
enable_testing()
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Babel src/*)
target_link_libraries(Babel ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)