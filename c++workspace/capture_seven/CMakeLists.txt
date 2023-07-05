cmake_minimum_required(VERSION 3.10)

project(CAPTURE_SEVEN
    VERSION 1.0
    DESCRIPTION "this is c++ learning project")

set(CMAKE_C_COMPILER  /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11)

message(STATUS "Cmake source Dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "project source dir: ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include) # 添加头文件

add_executable(classTest ${PROJECT_SOURCE_DIR}/src/segment_one.cpp) # 添加执行文件