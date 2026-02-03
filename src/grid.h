#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    void Initialize();
    void Print() const;
    void Draw(int offsetX, int offsetY) const;
    void SetGridCell(int row, int column, int value);
    bool IsCellOutside(int row, int column) const;
    bool IsCellEmpty(int row, int column) const;
    int ClearFullRows();

private:
    bool IsRowFull(int row) const;
    void ClearRow(int row);
    void MoveRowDown(int row, int count);
    std::vector<Color> colors;
    int grid[20][10] = {};
    int numRows;
    int numCols;
    int cellSize;
};