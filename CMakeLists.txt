cmake_minimum_required(VERSION 4.1)
project(labuba3)

set(CMAKE_CXX_STANDARD 20)

add_executable(labuba3 main.cpp
        Circle.cpp
        Circle.h
        Figures.h
        Figures.cpp
        Rectangle.cpp
        Rectangle.h
        trapezoid.h
        trapezoid.cpp
        triangle.cpp
        triangle.h
        Animal.h
        Fish.h
        Bird.h
        FlyingBird.h
        Human.h
        Human.cpp
        Student.h
        Student.cpp
        Teacher.h
        Teacher.cpp)
