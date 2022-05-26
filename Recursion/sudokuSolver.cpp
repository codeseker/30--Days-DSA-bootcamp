#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &sudoku, int n, int m, int val, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        // row check
        if (sudoku[row][i] == val)
        {
            return false;
        }
        // col
        if (sudoku[i][col] == val)
        {
            return false;
        }

        // 3 * 3 matrix check
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &sudoku, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // empty space
            if (sudoku[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(sudoku, n, m, val, i, j))
                    {
                        sudoku[i][j] = val;

                        bool nextAns = solve(sudoku, n, m);

                        if (nextAns)
                        {
                            return true;
                        }
                    }
                    // backtrack
                    sudoku[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    int n = sudoku.size();
    int m = sudoku[0].size();
    solve(sudoku, n, m);
}
int main()
{
    
    return 0;
}