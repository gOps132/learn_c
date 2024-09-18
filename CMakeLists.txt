cmake_minimum_required(VERSION 3.14)
project(learn_c
    DESCRIPTION "learnng the c fundamentals"
)

set(CMAKE_C_STANDARD 99)

add_subdirectory(DSA/binary_search)
add_subdirectory(DSA/circular_left_shifting)
add_subdirectory(DSA/fibonacci)

add_subdirectory(games/valid_sudoku)
add_subdirectory(games/donut)

add_subdirectory(examples/hello_world)
add_subdirectory(examples/strings)
add_subdirectory(examples/session_08_21)
add_subdirectory(examples/leap_year)
add_subdirectory(examples/bill_problem)
add_subdirectory(examples/elardo_calc)
add_subdirectory(examples/rectangle_area)