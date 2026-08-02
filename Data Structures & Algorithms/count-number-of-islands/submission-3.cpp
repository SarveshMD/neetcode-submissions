class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows;
    int cols;

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (auto [dr, dc]: directions) {
            int nr = i + dr;
            int nc = j + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};
