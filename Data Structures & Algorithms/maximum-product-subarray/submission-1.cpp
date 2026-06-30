class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMax = 1, curMin = 1;
        int res = *max_element(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                curMax = 1, curMin = 1;
                continue;
            }
            int tmp = curMax;
            curMax = max(curMax*nums[i], curMin*nums[i]);
            curMax = max(curMax, nums[i]);
            curMin = min(tmp*nums[i], curMin*nums[i]);
            curMin = min(curMin, nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};
