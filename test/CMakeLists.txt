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

#使用三方库的流程
#1.找库或者指定库位置
# set(XX "ccc") #指定库位置
#找库
find_library(Conn2_LIB NAMES Conn2 PATHS ${LIB})

if(NOT Conn2_LIB)
    MESSAGE(FATAL_ERROR "Conn2 NOT FOUND")
endif()

#2 指定库头文件位置
#target_include_directories(Conn2 PUBLIC ./inc)

#3 指定链接库的位置
#target_link_directories()

#4 需要链接的库
target_link_libraries(TEST PRIVATE ${Conn2_LIB})

#链接静态库
#link_libraries()
#链接动态库
#target_link_libraries()

#搜索文件
#aux_source_directory(<dir> <variable>)
#aux_source_directory(src SRC_LIST)
#file(GLOB/GLOB_RECURSE 变量名 搜索的文件路径和文件类型)
#file(GLOB MAIN_SRC src/*.cpp)
#file(GLOB HEAD_SRC src/*.h)

#包含头文件
#include_directories(headpath)

#日志
#message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] "message to display" ...)

#增加宏命令
#add_definitions()

