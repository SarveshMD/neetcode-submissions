class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, r = 0;
        int maxSum = nums[0];
        int currSum = 0;
        while (l <= r && l < nums.size() && r < nums.size()) {
            if (currSum < 0) {
                currSum = nums[r];
                l = r;
            }
            else {
                currSum += nums[r];
            }
            maxSum = max(maxSum, currSum);
            r++;
        }
        return maxSum;
    }
};
