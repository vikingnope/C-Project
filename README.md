# This is my CPS1011 Assignment
#### Created by Aiden Schembri

# Question 1  

## Description

In question 1 the program implements the Secant Method and the Newton-Raphson Method to find the closest root of a function. 
The appropriate error handling was done to make sure that the program runs smoothly.

## How to run

To run on Windows, kindly uncomment the lines 6 and 7 in the `CMakeLists.txt` file by removing the hashes in front:

```
MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
```

On other operating systems, the stack size is already set to 16 Mb.

In CLion reload the CMake project, then select `Question_1` in the configurations tab at the top right and run the program.

# Question 2    

## Description

In question 2 the program is designed to create a set with the ability to add, unionise sets,
intersect sets, find the symmetric difference between sets, check if a set is a subset of another set, check if a set is a proper subset of another set,
check if a set is empty, check if a set is equal to another set, check if a set is disjoint
from another set.

## How to run

### Question 2A
In CLion reload the CMake project, then select `Question_2A` in the configurations tab at the top right and run the program.

### Question 2B
In CLion reload the CMake project, then select `Question_2B` in the configurations tab at the top right and run the program.