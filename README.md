

To run on Windows, kindly uncomment the 2 lines (line 6 and 7) in the CMake Lists file by removing the hashes in front:

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")