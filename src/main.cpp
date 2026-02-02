#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

constexpr int screenWidth = 300;
constexpr int screenHeight = 600;

int main()
{
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    auto grid = Grid();
    grid.Print();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        grid.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}