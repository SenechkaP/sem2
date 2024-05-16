cmake_minimum_required(VERSION 3.26)
project(sem2)

set(CMAKE_CXX_STANDARD 17)

add_executable(sem2 main.cpp
        main.h
        account.h
        account.cpp)
