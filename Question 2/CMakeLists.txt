cmake_minimum_required(VERSION 3.26)
project("Assignment Question 2" C)

set(CMAKE_C_STANDARD 11)

add_executable(Question_2A Question2A.c)
add_executable(Question_2B Question2B.c)

add_library(GenSetLibA SHARED setMethodsA.c)
add_library(GenSetLibB SHARED setMethodsB.c)

target_link_libraries(Question_2A GenSetLibA)
target_link_libraries(Question_2B GenSetLibB)
