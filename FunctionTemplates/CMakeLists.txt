cmake_minimum_required(VERSION 3.21)
project(FunctionTemplates)

set(CMAKE_CXX_STANDARD 20)

add_executable(FunctionTemplates main.cpp defin_in_header.h module1.cpp module2.cpp module1.h module2.h)
