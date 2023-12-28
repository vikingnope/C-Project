cmake_minimum_required(VERSION 3.26)
project(Assignment C)

set(CMAKE_C_STANDARD 11)

#MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(Assignment_Question_1 Question1.c)
add_executable(Assignment_Question_2 Question2.c)
