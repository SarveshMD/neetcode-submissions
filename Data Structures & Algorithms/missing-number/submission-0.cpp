class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        for (int i=0; i<n; i++) {
            dp[nums[i]] = 1;
        }
        int missing;
        for (int i=0; i<n+1; i++) {
            if (dp[i] == 0) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};
