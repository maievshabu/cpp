cmake_minimum_required(VERSION 3.15)

#工程名称
project(TEST)

#设置变量
set(CMAKE_CXX_STANDARD 11)
set(LIB ${HOME}\\lib)

#输出
message(STATUS "LIB:${LIB}")

#include 搜索路径
include_directories(${HOME}/lib)

#执行文件
add_executable(TEST test.cpp)

#找库
find_library(Conn2_LIB NAMES Conn2 PATHS ${LIB})

if(NOT Conn2_LIB)
    MESSAGE(FATAL_ERROR "Conn2 NOT FOUND")
endif()

#链接库
target_link_libraries(TEST PRIVATE ${Conn2_LIB})