cmake_minimum_required(VERSION 3.21)
project(InstanceTemplManagement)

set(CMAKE_CXX_STANDARD 20)

add_executable(InstanceTemplManagement main.cpp tmp_max.h module1.cpp module2.cpp
        #tmplt_instance.h
        tmplt_instance.cpp)
