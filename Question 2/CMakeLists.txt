cmake_minimum_required(VERSION 3.26)
project("Assignment Question 2" C)

set(CMAKE_C_STANDARD 11)

add_executable(Question_2A Question2A.c)
add_executable(Question_2B Question2B.c)

add_library(GenSetLibA SHARED setMethodsA.c) # Creating a shared library for task A
add_library(GenSetLibB SHARED setMethodsB.c) # Creating a shared library for task B

target_link_libraries(Question_2A GenSetLibA) # Linking the library to the executable
target_link_libraries(Question_2B GenSetLibB) # Linking the library to the executable
