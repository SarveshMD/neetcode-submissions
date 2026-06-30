class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        for (int i=n-2; i>=0; i--) {
            int maxLIS = 1;
            for (int j=i+1; j<n; j++) {
                if (nums[i] < nums[j])
                    maxLIS = max(maxLIS, 1 + dp[j]);
            }
            dp[i] = maxLIS;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
