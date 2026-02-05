#include "game.h"
#include "block.h"
#include "random.h"
#include "audio.h"
#include <raylib.h>

Game::Game(const Audio &audio) : audio(audio) {
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    isGameOver = false;
    score = 0;
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }
    const int randomIndex = Random::GetRandomInt(0, static_cast<int>(blocks.size()) - 1);
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw(11, 11);
    currentBlock.Draw(11, 11);

    switch (nextBlock.GetId()) {
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }
}

void Game::HandleInput() {
    const int keyPressed = GetKeyPressed();

    if (isGameOver && keyPressed != 0) {
        isGameOver = false;
        Reset();
    }

    switch (keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
        default:
            break;
    }
}

void Game::MoveBlockLeft() {
    if (isGameOver) {
        return;
    }
    currentBlock.Move(0, -1);
    if (IsBlockOutside() || IsValidPosition() == false) {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight() {
    if (isGameOver) {
        return;
    }
    currentBlock.Move(0, 1);
    if (IsBlockOutside() || IsValidPosition() == false) {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown() {
    if (isGameOver) {
        return;
    }
    currentBlock.Move(1, 0);
    if (IsBlockOutside() || IsValidPosition() == false) {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

int Game::GetScore() const {
    return score;
}

bool Game::IsGameOver() const {
    return isGameOver;
}

void Game::RotateBlock() {
    if (isGameOver) {
        return;
    }
    currentBlock.Rotate();
    if (IsBlockOutside() || IsValidPosition() == false) {
        currentBlock.UndoRotation();
    }
    else {
        PlaySound(audio.GetRotate());
    }
}

void Game::LockBlock() {
    for (const auto tile: currentBlock.GetCellPosition()) {
        grid.SetGridCell(tile.row, tile.column, currentBlock.GetId());
    }
    currentBlock = nextBlock;
    if (IsValidPosition() == false) {
        isGameOver = true;
    }
    nextBlock = GetRandomBlock();

    if (const int cleared = grid.ClearFullRows(); cleared > 0) {
        PlaySound(audio.GetClear());
        UpdateScore(cleared, 0);
    }
}

void Game::Reset() {
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

bool Game::IsValidPosition() {
    const std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (int i = 0; i < tiles.capacity(); ++i) {
        if (grid.IsCellEmpty(tiles[i].row, tiles[i].column) == false) {
            return false;
        }
    }
    return true;
}

void Game::UpdateScore(const int linesCleared, const int moveDownPoints) {
    switch (linesCleared) {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        case 4:
            score += 700;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}

bool Game::IsBlockOutside()  {
    const std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (int i = 0; i < tiles.capacity(); ++i) {
        if (grid.IsCellOutside(tiles[i].row, tiles[i].column)) {
            return true;
        }
    }
    return false;
}