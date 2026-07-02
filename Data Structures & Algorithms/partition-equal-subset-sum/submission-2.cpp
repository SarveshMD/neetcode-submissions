class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, t;
        for (int num: nums) {
            sum += num;
        }
        if (sum%2 == 1) return false;
        else t = sum / 2;
        int n = nums.size();
        vector<bool> dp(t+1, 0);
        dp[0] = 1;
        if (nums[0] <= t) {
            dp[nums[0]] = 1;
        }
        for (int i=1; i<n; i++) {
            for (int j=t; j>=0; j--) {
                if (nums[i] <= j) {
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }
        return dp[t];
    }
};
