class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layers = n / 2;
        for (int lay=0; lay<layers; lay++) {
            for (int i=lay; i<n-lay-1; i++) {
                int tmp = matrix[lay][i];
                matrix[lay][i] = matrix[n-i-1][lay];
                matrix[n-i-1][lay] = matrix[n-lay-1][n-i-1];
                matrix[n-lay-1][n-i-1] = matrix[i][n-lay-1];
                matrix[i][n-lay-1] = tmp;
            }
        }
    }
};
