cmake_minimum_required(VERSION 3.14)
project(binary_search)

set(CMAKE_C_STANDARD 99)

set(SOURCES
    src/main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)