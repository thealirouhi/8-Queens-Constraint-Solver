#include <iostream>
using namespace std;

const int N = 8;

// read board from input
void readBoard(char board[N][N]);

// check if placing a queen is safe
bool isSafe(int queens[N], int row, int col, char board[N][N]);

// recursive solver
int solve(int queens[N], int row, char board[N][N]);

int main()
{
    char board[N][N];

    readBoard(board);

    int queens[N] = {0};

    int totalSolutions = solve(queens, 0, board);

    cout << totalSolutions << endl;

    return 0;
}