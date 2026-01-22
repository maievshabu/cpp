cmake_minimum_required(VERSION 3.21)
project(c11)

set(CMAKE_CXX_STANDARD 11)
#
# RVO (Return Value Optimization) 和 NRVO (Named Return Value Optimization)
# 是编译器的优化策略。
# 在很多情况下，编译器会直接在调用者的栈上构造返回值对象，而不是先构造 p1 再移动/拷贝。
# 这意味着：可能既不会调用拷贝构造，也不会调用移动构
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

add_executable(c11
        main.cpp
        d117.cpp
        d119.cpp
        d120.cpp
        d121.cpp
        d122.cpp
        )
