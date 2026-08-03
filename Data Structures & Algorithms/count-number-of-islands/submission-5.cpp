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

    void bfs(vector<vector<char>>& grid, int r, int c) {

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dr, dc]: directions) {
                int nr = i + dr;
                int nc = j + dc;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

                if (grid[nr][nc] == '0') continue;

                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int nIslands = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};
