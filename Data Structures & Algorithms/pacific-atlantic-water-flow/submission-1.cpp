class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1},{0,1}};

    bool a_dfs(vector<vector<int>>& heights, int row, int col, 
    vector<vector<int>>& a_visited, vector<vector<int>>& reaches_a) {
        a_visited[row][col] = 1;
        int m = heights.size();
        int n = heights[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n) return false;
        if (row == m - 1 || col == n - 1) {
            reaches_a[row][col] = 1;
            return true;
        }
        bool reaches = false;
        for (auto direction: directions) {
            int r = row+direction[0]; int c = col+direction[1];
            if (r>=0 && r<m && c>=0 && c<n && !reaches && heights[row][col] >= heights[r][c]) {
                if (a_visited[r][c]) {
                    reaches = reaches_a[r][c];
                }
                else {
                    reaches = a_dfs(heights, r, c, a_visited, reaches_a);
                }
            }
        }
        reaches_a[row][col] = (int)reaches;
        return reaches;
    }
    
    bool p_dfs(vector<vector<int>>& heights, int row, int col, 
    vector<vector<int>>& p_visited, vector<vector<int>>& reaches_p) {
        p_visited[row][col] = 1;
        int m = heights.size();
        int n = heights[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n) return false;
        if (row == 0 || col == 0) {
            reaches_p[row][col] = 1;
            return true;
        }
        bool reaches = false;
        for (auto direction: directions) {
            int r = row+direction[0]; int c = col+direction[1];
            if (r>=0 && r<m && c>=0 && c<n && !reaches && heights[row][col] >= heights[r][c]) {
                if (p_visited[r][c]) {
                    reaches = reaches_p[r][c];
                }
                else {
                    reaches = p_dfs(heights, r, c, p_visited, reaches_p);
                }
            }
        }
        reaches_p[row][col] = (int)reaches;
        return reaches;
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;

        vector<vector<int>> p_visited(m, vector<int>(n,0));
        vector<vector<int>> reaches_p(m, vector<int>(n,0));
        vector<vector<int>> a_visited(m, vector<int>(n,0));
        vector<vector<int>> reaches_a(m, vector<int>(n,0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!a_visited[i][j]) {
                    a_dfs(heights, i, j, a_visited, reaches_a);
                }
                if (!p_visited[i][j]) {
                    p_dfs(heights, i, j, p_visited, reaches_p);
                }
                if (reaches_a[i][j] && reaches_p[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
