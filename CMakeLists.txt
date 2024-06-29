cmake_minimum_required(VERSION 3.27)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)

add_executable(Coursework main.cpp
        Book.h
        People.cpp
        Author.cpp
        Book.cpp
        Bookstand.h)
