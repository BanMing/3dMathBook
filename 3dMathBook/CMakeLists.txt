cmake_minimum_required(VERSION 3.15)
project(3d_math_book)

#头文件目录 header
#include_directories(header)

set(CMAKE_CXX_STANDARD 17)
#设置源文件
file(GLOB HEADERS "header/*.h")
#设置源文件
file(GLOB SOURCES "src/*.cpp")


add_executable(3d_math_book main.cpp ${HEADERS} ${SOURCES})