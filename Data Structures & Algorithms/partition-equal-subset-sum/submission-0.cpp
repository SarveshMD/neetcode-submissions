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
        vector<vector<bool>> dp(n, vector<bool>(t+1, 0));
        for (int i=0; i<n; i++) {
            if (i == 0) {
                dp[i][0] = 1;
                if (nums[i] <= t) {
                    dp[i][nums[i]] = 1;
                }
                continue;
            }
            for (int j=0; j<t+1; j++) {
                dp[i][j] = dp[i-1][j];
                if (nums[i] <= j) {
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][t];
    }
};
