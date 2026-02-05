#pragma once
#include <vector>
#include <raylib.h>
#include <array>

class Grid {
public:
    Grid();
    void Initialize();
    void Print() const;
    void Draw(int offsetX, int offsetY) const;
    void SetGridCell(int row, int column, int value);
    [[nodiscard]] bool IsCellOutside(int row, int column) const;
    [[nodiscard]] bool IsCellEmpty(int row, int column) const;
    int ClearFullRows();

private:
    [[nodiscard]] bool IsRowFull(int row) const;
    void ClearRow(int row);
    void MoveRowDown(int row, int count);
    std::vector<Color> colors;
    std::array<std::array<int, 10>, 20> grid{};
    int numRows;
    int numCols;
    int cellSize;
};