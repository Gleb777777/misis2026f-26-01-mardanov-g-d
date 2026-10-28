cmake_minimum_required(VERSION 3.20)
project(codeforces)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXE_NAME} EXCLUDE_FROM_ALL ${SOURCE_FILE})
endforeach()