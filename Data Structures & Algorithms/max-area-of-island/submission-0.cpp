class Solution {
public:
    int maxArea = 0;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};

    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (!grid[row][col] || visited[row][col]) return 0;
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = true;
        int totalArea = 0;
        for (int i=0; i<4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            totalArea += dfs(grid, nr, nc, visited);
        }
        return totalArea + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j])
                    maxArea = max(maxArea, dfs(grid, i, j, visited));
            }
        }
        return maxArea;
    }
};
