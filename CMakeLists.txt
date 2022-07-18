cmake_minimum_required(VERSION 3.22)
project(personfinder C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(personfinder
        header.c
        header.h
        main.c)
