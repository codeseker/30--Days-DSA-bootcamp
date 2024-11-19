class Solution {
public:
    int solveRec(int row, int col, int n, int m) {
        if(row == 0 && col == 0) return 1;

        int left = 0;
        if(col > 0) {
            left = solveRec(row, col-1, n, m);
        }
        int top = 0;
        if(row > 0) {
            top = solveRec(row-1, col, n, m);
        }

        return left + top;
    }

    int solveMem(int row, int col, int n, int m, vector<vector<int>> &dp) {
        if(row == 0 && col == 0) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int left = 0;
        if(col > 0) {
            left = solveMem(row, col-1, n, m, dp);
        }
        int top = 0;
        if(row > 0) {
            top = solveMem(row-1, col, n, m, dp);
        }

        return dp[row][col] = left + top;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solveMem(m-1, n-1, m, n, dp);
    }
};