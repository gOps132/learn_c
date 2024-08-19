cmake_minimum_required(VERSION 3.14)
project(hello_world)

set(CMAKE_C_STANDARD 99)

set(c_learn_sources
    src/main.c
)

add_executable(${PROJECT_NAME} ${c_learn_sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)