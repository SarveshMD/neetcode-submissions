class Solution {
public:
    int islands = 0;

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c) {
        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
            for (auto direction: directions) {
                r = row + direction.first;
                c = col + direction.second;
                if (r >= 0 && r < grid.size() &&
                    c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1' &&
                    !visited[r][c]) {
                    q.push({r,c});
                    visited[r][c] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1' &&
                    !visited[i][j]) {
                        bfs(grid, visited, i, j);
                        islands++;
                }
            }
        }
        return islands;
    }
};
