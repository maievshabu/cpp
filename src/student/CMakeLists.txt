cmake_minimum_required(VERSION 3.21)
PROJECT(STUDENT)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(STUDENT
        main.cpp
        Student.cpp
        Report.cpp
        Person.cpp
        Course.cpp
        )