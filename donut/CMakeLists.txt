cmake_minimum_required(VERSION 3.14)
project(donut)

set(CMAKE_C_STANDARD 99)

set("${PROJECT_NAME}/sources"
    src/main.c
)

add_executable(${PROJECT_NAME} "${PROJECT_NAME}/sources"})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)