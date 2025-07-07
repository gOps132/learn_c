cmake_minimum_required(VERSION 3.14)
project(RaylibTemplate)

set(CMAKE_C_STANDARD 99)

set(raylib_proj
    src/main.c
)

# Add raylib from root's lib directory
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/raylib ${CMAKE_BINARY_DIR}/raylib_build)

# Create executable
add_executable(${PROJECT_NAME} ${raylib_proj})

# Set build flags and output directories
set_target_properties(${PROJECT_NAME} PROPERTIES 
    LINKER_LANGUAGE C
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)

# Link raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Link macOS frameworks (correct signature)
if (APPLE)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            "-framework IOKit"
            "-framework Cocoa"
            "-framework OpenGL"
    )
endif()

