cmake_minimum_required(VERSION 3.23)
project(OOP1_Integral_calc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(OOP1_Integral_calc)

add_executable(OOP1_Integral_calc
        OOP1_Integral_calc/OOP1_Integral_calc.cpp
        OOP1_Integral_calc.sln)
