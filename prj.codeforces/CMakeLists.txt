cmake_minimum_required(VERSION 3.20)
project(prj.codeforces)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp")

foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE_FILE} "118a.cpp" "158a.cpp" "050a.cpp" "282a.cpp" "0112a.cpp")
endforeach()