class Solution {
public:
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1},{0,1}};
    
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>>& visited, int prevHeight) {
        if (row < 0 || row >= heights.size() ||
            col < 0 || col >= heights[0].size() ||
            visited[row][col] || heights[row][col] < prevHeight)
            return;
        visited[row][col] = 1;
        int currHeight = heights[row][col];
        for (const auto& [r,c]: directions) {
            dfs(heights, row+r, col+c, visited, currHeight);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        vector<vector<int>> res;

        for (int i=0; i<m; i++) {
            dfs(heights, i, 0, pacific, heights[i][0]);
            dfs(heights, i, n-1, atlantic, heights[i][n-1]);
        }

        for (int j=0; j<n; j++) {
            dfs(heights, 0, j, pacific, heights[0][j]);
            dfs(heights, m-1, j, atlantic, heights[m-1][j]);
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
