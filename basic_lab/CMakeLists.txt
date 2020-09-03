cmake_minimum_required(VERSION 3.10)
project(basic_lab)

#头文件目录 header
include_directories(${PROJECT_SOURCE_DIR}/header)

#set(CMAKE_CXX_STANDARD 17)

# 搜索src模板下的cpp文件（顶层）设置到变量SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*cpp)

# 打印
#message(${SOURCE_FILES})

add_executable(basic_lab main.cpp ${SOURCE_FILES})

