class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m-1;
        int row;
        while (top <= bottom) {
            row = (top + bottom)/2;
            if (target > matrix[row][n-1]) top = row+1;
            else if (target >= matrix[row][0]) break;
            else bottom = row-1;
        }
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (target == matrix[row][mid]) return true;
            else if (target < matrix[row][mid]) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};
