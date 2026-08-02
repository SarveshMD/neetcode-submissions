class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        for (auto& direction: directions) {
            int rr = i + direction[0];
            int cc = j + direction[1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == '1') {
                dfs(grid, rr, cc, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return islands;
    }
};
