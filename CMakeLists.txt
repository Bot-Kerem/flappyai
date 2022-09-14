cmake_minimum_required(VERSION 3.23.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(glfw3 REQUIRED)
message("FIND GLFW AT: ${glfw3_DIR}")

project(flappyai)

set(PROJECT_SOURCES
    src/main.cpp
    src/window.cpp
    src/game.cpp
    src/pipe.cpp
    src/pipemanager.cpp
    src/bird.cpp
    src/shader.cpp

    lib/glad/src/glad.c
    )

set(PROJECT_INLCUDES
    lib/glad/include
    include/
    )

add_executable(flappyai ${PROJECT_SOURCES})

target_link_libraries(flappyai PRIVATE glfw)

target_include_directories(flappyai PUBLIC ${PROJECT_INLCUDES})
