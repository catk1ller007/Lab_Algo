cmake_minimum_required(VERSION 3.25)

project(ConsoleApplication1)

set(SOURCE_EXE main.cpp)

include_directories(./Algorithms/sources)
include_directories(./Algorithms/headers)
include_directories(./AVL/headers)
include_directories(./AVL/sources)
include_directories(./Tests/sources)
include_directories(./Tests/headers)
include_directories(./headers)


# Algorithms
set(ALGORITHMS_SRC Algorithms/sources/Algorithms.cpp)
set(ALGORITHMS_HDR Algorithms/headers/Algorithms.h)
add_library(algs_lib ${ALGORITHMS_SRC} ${ALGORITHMS_HDR})

# Tests
set(TESTS_SRC Tests/sources/Test.cpp)
set(TESTS_HDR Tests/headers/Test.h)
add_library(tests_lib ${TESTS_SRC} ${TESTS_HDR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} algs_lib)
target_link_libraries(${PROJECT_NAME} tests_lib)