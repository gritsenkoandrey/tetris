#include <raylib.h>
#include <iostream>
#include "game.h"
#include "colors.h"

constexpr int screenWidth = 500;
constexpr int screenHeight = 620;

double lastUpdateTime = 0;

bool EventTriggered(const double interval) {
    const double currentTime = GetTime();
    if (currentTime - lastUpdateTime > interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    const Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    auto game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();

        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.isGameOver) {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, lightBlue);
        std::string scoreText = std::to_string(game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText.c_str(), 38, 2);
        DrawTextEx(font, scoreText.c_str(), {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3f, 6, lightBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}