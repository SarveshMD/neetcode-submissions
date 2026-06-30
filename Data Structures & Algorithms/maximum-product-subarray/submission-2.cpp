class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMax = 1, curMin = 1;
        int res = *max_element(nums.begin(), nums.end());

        for (int num: nums) {
            if (num == 0) {
                curMax = 1, curMin = 1;
                continue;
            }
            int tmp = curMax;
            curMax = max(curMax*num, curMin*num);
            curMax = max(curMax, num);
            curMin = min(tmp*num, curMin*num);
            curMin = min(curMin, num);
            res = max(res, curMax);
        }
        return res;
    }
};
