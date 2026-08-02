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

    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        int area = 1;

        for (auto [dr, dc]: directions) {
            int nr = dr + i;
            int nc = dc + j;
            
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

            if (grid[nr][nc]) {
                area += dfs(grid, nr, nc);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxArea = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
