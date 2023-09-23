CMAKE_MINIMUM_REQUIRED(VERSION 3.25.0)

project(
    lab_alg
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./algo)
include_directories(./tests)
include_directories(./avl)
include_directories(./hdr)

# Algorithms
set(ALGORITHMS_SRC algo/Algorithms.cpp)
set(ALGORITHMS_HDR algo/Algorithms.h)
add_library(algs_lib ${ALGORITHMS_SRC} ${ALGORITHMS_HDR})

# Tests
set(TESTS_SRC tests/Tests.cpp)
set(TESTS_HDR tests/Tests.h)
add_library(tests_lib ${TESTS_SRC} ${TESTS_HDR})

# Avl Tree
set(AVL_SRC avl/AVL.cpp)
set(AVL_HDR avl/AVL.h)
add_library(avl_lib ${AVL_SRC} ${AVL_HDR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} algs_lib)
target_link_libraries(${PROJECT_NAME} tests_lib)
target_link_libraries(${PROJECT_NAME} avl_lib)