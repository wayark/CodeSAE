cmake_minimum_required(VERSION 3.20)
project(prog C)

set(CMAKE_C_STANDARD 99)

add_executable(prog main.c client.c client.h add.h add.c)
