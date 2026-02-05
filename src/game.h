#pragma once
#include "audio.h"
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
    explicit Game(const Audio &audio);
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    [[nodiscard]] int GetScore() const;
    [[nodiscard]] bool IsGameOver() const;
private:
    Block GetRandomBlock();
    static std::vector<Block> GetAllBlocks();
    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void LockBlock();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    bool IsBlockOutside();
    bool IsValidPosition();
    bool isGameOver;
    int score;
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    const Audio &audio;
};