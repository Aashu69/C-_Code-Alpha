#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int grid[N][N]) {
    cout << "\nSolved Sudoku:\n";
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0)
            cout << "------+-------+------\n";
        for (int d = 0; d < N; d++) {
            if (d % 3 == 0 && d != 0) cout << "| ";
            cout << grid[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N];
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                cout << "Invalid input. Please enter numbers between 0-9.\n";
                return 1;
            }
        }
    }

    auto start = high_resolution_clock::now();

    if (solveSudoku(grid)) {
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        printGrid(grid);
        cout << "\nSolved in " << duration.count() << " ms.\n";
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}