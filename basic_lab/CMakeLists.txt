cmake_minimum_required(VERSION 3.10)
project(basic_lab)

#头文件目录 header
include_directories(${PROJECT_SOURCE_DIR}/header)

#set(CMAKE_CXX_STANDARD 17)

# 搜索src模板下的cpp文件（顶层）设置到变量SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*cpp)

# 打印
#message(${SOURCE_FILES})

# 这里设置两个库 dome_src dome_libsrc
# 这里有个奇异的点就是 库的名字必须是${PROJECT_NAME}这个开头 不然无法链接到
#add_library(${PROJECT_NAME}_src SHARED ${SOURCE_FILES})

add_executable(basic_lab main.cpp ${SOURCE_FILES})

# 这里把库文件链接到可执行文件中
#target_link_libraries(${PROJECT_NAME}
#${PROJECT_NAME}_src
#)