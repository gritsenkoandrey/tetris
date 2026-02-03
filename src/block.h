#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int row, int column);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPosition();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
};