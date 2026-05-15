#include <iostream>
using namespace std;

const int N = 8;

// read board from input
void readBoard(char board[N][N]);

// check if placing a queen is safe
bool isSafe(int queens[N], int row, int col, char board[N][N]);

// recursive solver
int solve(int queens[N], int row, char board[N][N]);

void readBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < N; j++) {
            board[i][j] = row[j];
        }
    }
}

bool isSafe(int queens[N], int row, int col, char board[N][N]) {

    // 1. obstacle check
    if (board[row][col] == '*')
        return false;

    // 2. check against all previously placed queens
    for (int r = 0; r < row; r++) {

        int c = queens[r];

        // same column
        if (c == col)
            return false;

        // diagonal conflict
        if (abs(r - row) == abs(c - col))
            return false;
    }

    return true;
}

int main()
{
    char board[N][N];

    readBoard(board);

    int queens[N] = {0};

    int totalSolutions = solve(queens, 0, board);

    cout << totalSolutions << endl;

    return 0;
}