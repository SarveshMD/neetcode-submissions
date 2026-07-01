class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res = {};
        int t = 0, b = m;
        int l = 0, r = n;
        while (t < b && l < r) {
            for (int i=l; i<r; i++) {
                res.push_back(matrix[t][i]);
            }
            t++;
            for (int i=t; i<b; i++) {
                res.push_back(matrix[i][r-1]);
            }
            r--;
            if (res.size() == m*n) break;
            for (int i=r-1; i>=l; i--) {
                res.push_back(matrix[b-1][i]);
            }
            b--;
            for (int i=b-1; i>=t; i--) {
                res.push_back(matrix[i][l]);
            }
            l++;
        }
        return res;
    }
};
