cmake_minimum_required(VERSION 3.26)
project("Assignment Question 2" C)

set(CMAKE_C_STANDARD 11)

add_executable(Question_2A Question2A.c SetMethodsA.c)
add_executable(Question_2B Question2B.c setMethodsB.c)

set(LIB_SOURCE_FILES
    setMethodsB.c
)

set(LIB_HEADER_FILES
    setMethodsB.h
)

add_library(GenSet SHARED ${LIB_SOURCE_FILES} ${LIB_HEADER_FILES})

set_target_properties(GenSet PROPERTIES VERSION 1.0)

install(TARGETS GenSet LIBRARY DESTINATION lib)
install(FILES ${LIB_HEADER_FILES} DESTINATION include)

target_link_libraries(Question_2A GenSet)
target_link_libraries(Question_2B GenSet)
