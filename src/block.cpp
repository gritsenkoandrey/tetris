#include "block.h"

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw() {
    for (const Position item: cells[rotationState]) {
        DrawRectangle(
            item.column * cellSize + 1,
            item.row * cellSize + 1,
            cellSize - 1,
            cellSize - 1,
            colors[id]);
    }
}