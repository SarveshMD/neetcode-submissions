class Solution {
public:
    int maxArea = 0;
    int m;
    int n;
    vector<pair<int, int>> directions = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    int bfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int,int>> bfs_queue;
        bfs_queue.push({row, col});
        grid[row][col] = 0;

        int islandArea = 1;

        while (!bfs_queue.empty()) {
            auto [nr, nc] = bfs_queue.front();
            bfs_queue.pop();
            for (auto dir: directions) {
                int dr = nr + dir.first;
                int dc = nc + dir.second;
                if (dr < 0 || dc < 0 || dr >= m || dc >= n) {
                    continue;
                }
                if (grid[dr][dc] == 1) {
                    bfs_queue.push({dr,dc});
                    grid[dr][dc] = 0;
                    islandArea++;
                }
            }
        }
        return islandArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    int islandArea = bfs(grid, i, j);
                    maxArea = max(maxArea, islandArea);
                }
            }
        }
        return maxArea;
    }
};
