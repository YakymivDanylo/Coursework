cmake_minimum_required(VERSION 3.27)
project(Coursework)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Coursework main.cpp
        Book.h
        Book.cpp
        Author.h
        Author.cpp
        Person.cpp
        Person.h
        Bookstand.cpp
        Bookstand.h
        Reader.h
        Reader.cpp
        SameID.h
        BookIsInFile.h
        FileReader.h
        InstructionReader.h
)
