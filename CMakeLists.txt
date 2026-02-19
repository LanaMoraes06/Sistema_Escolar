cmake_minimum_required(VERSION 3.20)
project(Sistema)

set(CMAKE_CXX_STANDARD 14)

include_directories(adm)

add_executable(Sistema
        adm/Main.cpp
        adm/School.cpp
        adm/Student.cpp
        adm/Teacher.cpp
        adm/Person.cpp
        adm/Director.cpp
)