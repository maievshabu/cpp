cmake_minimum_required(VERSION 3.15)
PROJECT(STL)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SRC_LIST main.cpp stl.cpp)

set(LIB ${SOURCE_HOME}/lib64)
message(STATUS "LIB:${LIB}")

include_directories(${LIB})

add_executable(STL ${SRC_LIST})

# 检查库是否找到
find_library(CALC_LIB NAMES CALC-STATIC PATHS ${LIB} ${SOURCE_HOME}/lib64)
#找库
message(STATUS "LIB1:${CALC_LIB}")

# 链接库文件
if(NOT CALC_LIB)
    message(FATAL_ERROR ":::Library not found")
endif()

set(EXECUTABLE_OUTPUT_PATH ${SOURCE_HOME}/bin)
target_link_libraries(STL PRIVATE ${CALC_LIB})
