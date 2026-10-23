class Solution {
public:
    vector<pair<int,int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    bool validIndex(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        if (!validIndex(grid, row, col)) return;

        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = '0';

        while (!q.empty()) {
            auto [nr, nc] = q.front();
            q.pop();

            for (auto dir: directions) {
                int dr = nr + dir.first;
                int dc = nc + dir.second;
                if (!validIndex(grid, dr, dc)) continue;
                
                if (grid[dr][dc] == '1') {
                    q.push({dr,dc});
                    grid[dr][dc] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
