#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() const {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw(const int offsetX, const int offsetY) const {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            const int cellValue = grid[row][col];
            DrawRectangle(
                col * cellSize + offsetX,
                row * cellSize + offsetY,
                cellSize - 1,
                cellSize - 1,
                colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(const int row, const int column) const {
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }

    return true;
}

bool Grid::IsCellEmpty(const int row, const int column) const {
    if (grid[row][column] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() {
    int completed = 0;
    for (int row = numRows - 1; row >= 0; --row) {
        if (IsRowFull(row)) {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

void Grid::SetGridCell(const int row, const int column, const int value) {
    grid[row][column] = value;
}

bool Grid::IsRowFull(const int row) const {
    for (int col = 0; col < numCols; col++) {
        if (grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(const int row) {
    for (int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(const int row, const int count) {
    for (int col = 0; col < numCols; col++) {
        grid[row + count][col] = grid[row][col];
        grid[row][col] = 0;
    }
}