cmake_minimum_required(VERSION 3.15)
project(3d_math_book)

#头文件目录 header
include_directories(header)

set(CMAKE_CXX_STANDARD 17)

add_library(sources
        src/MathUtil.cpp
        src/EulerAngles.cpp src/Quaternion.cpp)

add_executable(3d_math_book main.cpp ${sources} )