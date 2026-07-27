class Solution {
public:
    int maxArea(vector<int>& heights) {
        int highest = 0;
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            highest = max(highest, (right-left)*min(heights[right], heights[left]));
            if (heights[left] <= heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return highest;
    }
};
