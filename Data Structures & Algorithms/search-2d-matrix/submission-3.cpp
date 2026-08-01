class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0, down = m-1;
        int row;
        while (up <= down) {
            int mid = (up + down) / 2;
            if (target < matrix[mid][0]) down = mid - 1;
            else if (matrix[mid][n-1] < target) up = mid + 1;
            else {
                row = mid;
                break;
            }
        }
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) return true;
            else if (target < matrix[row][mid]) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
