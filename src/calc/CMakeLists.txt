cmake_minimum_required(VERSION 3.5)
PROJECT(CALC)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
add_library(CALC SHARED Calc.cpp)
add_library(CALC-STATIC STATIC Calc.cpp)
message(STATUS "calc-SOURCE_HOME:${SOURCE_HOME}")
install(FILES Calc.h DESTINATION ${SOURCE_HOME}/include)

install(TARGETS CALC CALC-STATIC
        EXPORT CALCTargets
        DESTINATION ${SOURCE_HOME}/lib64
        )
install(EXPORT CALCTargets
        FILE CALCConfig.cmake
        NAMESPACE CALC::
        DESTINATION ${SOURCE_HOME}/lib64/cmake
        )
