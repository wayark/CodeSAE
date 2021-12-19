cmake_minimum_required(VERSION 3.20)
project(prog C)

set(CMAKE_C_STANDARD 99)

add_executable(prog file/main.c file/client.c file/client.h file/add.h file/add.c file/trier.h file/trier.c)
