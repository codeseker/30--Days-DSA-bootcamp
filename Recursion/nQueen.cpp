#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // row check
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // diagonal row check
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    // diagonal col check
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}
void addSolutions(vector<vector<int>> &board, int n, vector<vector<int>> &ans)
{
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp.push_back(board[i][j]);
        }
    }
    ans.push_back(tmp);
}
void solve(vector<vector<int>> &board, int n, vector<vector<int>> &ans, int col)
{
    // base case
    if (col == n)
    {
        addSolutions(board, n, ans);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 1;
            solve(board, n, ans, col + 1);
            board[i][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, n, ans, 0);
    return ans;
}

int main()
{
    return 0;
}