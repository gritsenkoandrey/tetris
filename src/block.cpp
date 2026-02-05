#include "block.h"
#include "colors.h"
#include <raylib.h>

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
    id = 0;
    colors = GetCellColors();
}

void Block::Draw(const int offsetX, const int offsetY) {
    for (const Position item: GetCellPosition()) {
        DrawRectangle(
            item.column * cellSize + offsetX,
            item.row * cellSize + offsetY,
            cellSize - 1,
            cellSize - 1,
            colors[id]);
    }
}

void Block::Move(const int row, const int column) {
    rowOffset += row;
    columnOffset += column;
}

std::vector<Position> Block::GetCellPosition() {
    const std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> moveTiles;

    for (const Position tile: tiles) {
        auto newPosition = Position(tile.row + rowOffset, tile.column + columnOffset);
        moveTiles.push_back(newPosition);
    }

    return moveTiles;
}

void Block::Rotate() {
    rotationState++;
    if (rotationState == cells.size()) {
        rotationState = 0;
    }
}

void Block::UndoRotation() {
    rotationState--;
    if (rotationState == -1) {
        rotationState = static_cast<int>(cells.size() - 1);
    }
}

int Block::GetId() const{
    return id;
}