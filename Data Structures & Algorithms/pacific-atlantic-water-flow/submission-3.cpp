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

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;

        for (auto [dr, dc]: directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            
            if (heights[r][c] <= heights[nr][nc] && !ocean[nr][nc]) {
                dfs(heights, nr, nc, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (i == 0 || j == 0) pacific[i][j] = true;
                if (i == rows-1 || j == cols-1) atlantic[i][j] = true;
            }
        }

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (pacific[i][j]) {
                    dfs(heights, i, j, pacific);
                }
                if (atlantic[i][j]) {
                    dfs(heights, i, j, atlantic);
                }
            }
        }

        vector<vector<int>> res;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
