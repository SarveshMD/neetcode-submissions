class Solution {
public:
    int maxArea = 0;
    int currArea = 0;
    int rows;
    int cols;
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void dfs(vector<vector<int>>& grid, int i, int j) {
        maxArea = max(maxArea, currArea);

        grid[i][j] = 0;
        for (auto [dr, dc]: directions) {
            int nr = dr + i;
            int nc = dc + j;
            
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

            if (grid[nr][nc]) {
                currArea++;
                dfs(grid, nr, nc);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]) {
                    currArea = 1;
                    dfs(grid, i, j);
                }
            }
        }
        return maxArea;
    }
};
