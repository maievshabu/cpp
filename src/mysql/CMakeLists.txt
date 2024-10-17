cmake_minimum_required(VERSION 3.15)
PROJECT(MYSQL)

set(CMAKE_CXX_STANDARD 11)
set(HOME "C:\\work\\untitled")

#set(EXECUTABLE_OUTPUT_PATH ${HOME}\\bin)
set(LIBRARY_OUTPUT_PATH ${HOME}/lib)
set(INC_DIR ${PROJECT_BINARY_DIR}/inc)
#include_directories(${INC_DIR})

add_library(Conn2 STATIC ./conn2.cpp)
add_library(Conn1 SHARED ./conn.cpp)

#target_link_libraries(MYSQL PRIVATE Conn2)
install(
        TARGETS Conn2 Conn1
        ARCHIVE DESTINATION ${HOME}/lib
        LIBRARY DESTINATION ${HOME}/lib
)

install(DIRECTORY inc/ DESTINATION ${HOME}/lib)
