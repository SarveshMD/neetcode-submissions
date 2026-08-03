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

    queue<pair<int, int>> q;

    void bfs(vector<vector<char>>& grid) {

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
                    q.push({i, j});
                    grid[i][j] = '0';
                    nIslands++;
                    bfs(grid);
                }
            }
        }
        return nIslands;
    }
};
