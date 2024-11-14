#include <iostream>
#include <cmath>
using namespace std;

int board[20], solutionCount = 0;

void printSolution(int n) {
    cout << "\nSolution " << ++solutionCount << ":\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

bool canPlace(int row, int col) {
    for (int i = 1; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int row, int n) {
    if (row > n) {
        printSolution(n);
        return;
    }
    for (int col = 1; col <= n; ++col) {
        if (canPlace(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;
    solveNQueens(1, n);
    return 0;
}

