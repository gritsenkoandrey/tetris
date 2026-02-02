cmake_minimum_required(VERSION 3.20)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)

FetchContent_MakeAvailable(raylib)
add_executable(Tetris src/main.cpp
        src/grid.h
        src/grid.cpp
        src/block.h
        src/position.h
        src/position.cpp
        src/colors.h
        src/colors.cpp
        src/block.cpp
        src/blocks.cpp
)
target_link_libraries(Tetris PRIVATE raylib)