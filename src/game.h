#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool isGameOver;
    int score;
    Music music;
private:
    Block GetRandomBlock();
    static std::vector<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void LockBlock();
    void Reset();
    bool IsValidPosition();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};