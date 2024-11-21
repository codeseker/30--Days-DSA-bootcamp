class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = currRow + r[i];
                int y = currCol + c[i];

                while (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'W' && grid[x][y] != 'G') {
                    if (vis[x][y] == 0) vis[x][y] = 1;
                    x += r[i];
                    y += c[i];
                }
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(m, n);
        vector<vector<char>> grid(n, vector<char>(m, '.'));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (auto it : guards) {
            int row = it[0];
            int col = it[1];
            grid[row][col] = 'G';
        }

        for (auto it : walls) {
            int row = it[0];
            int col = it[1];
            grid[row][col] = 'W';
            vis[row][col] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'G') {
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};
