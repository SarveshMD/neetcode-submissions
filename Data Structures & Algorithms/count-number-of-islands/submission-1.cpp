class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<bool>>& visited) {
        if(visited[i][j]) return;
        visited[i][j] = true;
        for (auto& direction: directions) {
            int rr = i + direction[0];
            int cc = j + direction[1];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n &&
            !visited[rr][cc] && grid[rr][cc] == '1') {
                dfs(grid, rr, cc, m, n, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, m, n, visited);
                }
            }
        }
        return islands;
    }
};
