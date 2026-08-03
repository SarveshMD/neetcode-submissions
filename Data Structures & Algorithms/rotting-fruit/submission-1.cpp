class Solution {
public:
    int rows;
    int cols;
    int freshTomatoes = 0;
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int timeTaken = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            int infectedAnyone = false;
            while (levelSize--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc]: directions) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshTomatoes--;
                        infectedAnyone = true;
                    }
                }
            }
            if (infectedAnyone) timeTaken++;
        }
        return timeTaken;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 1) freshTomatoes++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int timeTaken = bfs(grid, q);
        if (freshTomatoes > 0) return -1;
        return timeTaken;
    }
};
