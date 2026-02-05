#include <raylib.h>
#include <string>
#include "game.h"
#include "colors.h"

constexpr int screenWidth = 500;
constexpr int screenHeight = 620;

bool EventTriggered(const double interval) {
    static double lastUpdateTime = 0;
    if (const double currentTime = GetTime(); currentTime - lastUpdateTime > interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    const Font font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);

    const auto audio = Audio();
    auto game = Game(audio);

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(audio.GetMusic());
        game.HandleInput();

        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.IsGameOver()) {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, lightBlue);
        std::string scoreText = std::to_string(game.GetScore());
        float sizeX = MeasureTextEx(font, scoreText.c_str(), 38, 2).x;
        DrawTextEx(font, scoreText.c_str(), {320 + (170 - sizeX) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3f, 6, lightBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}