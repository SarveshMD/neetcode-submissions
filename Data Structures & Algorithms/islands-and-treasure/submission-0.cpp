class Solution {
public:
    int rows;
    int cols;
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc]: directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

                if (grid[nr][nc] == -1) continue;

                if (grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = 1 + grid[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        bfs(grid, q);
    }
};
