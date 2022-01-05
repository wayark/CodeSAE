cmake_minimum_required(VERSION 3.20)
project(prog C)

set(CMAKE_C_STANDARD 99)

add_executable(prog file/main.c file/client.c file/client.h file/add.h file/add.c file/trier.h file/trier.c file/filter.c file/filter.h file/search.c file/search.h file/blank.c file/blank.h file/modifier.c file/modifier.h file/supprimer.c file/supprimer.h file/save.c file/save.h)
