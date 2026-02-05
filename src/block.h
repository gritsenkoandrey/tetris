#pragma once
#include <vector>
#include <map>
#include <raylib.h>
#include "position.h"

class Block {
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int row, int column);
    void Rotate();
    void UndoRotation();
    [[nodiscard]] int GetId() const;
    std::vector<Position> GetCellPosition();

protected:
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
};