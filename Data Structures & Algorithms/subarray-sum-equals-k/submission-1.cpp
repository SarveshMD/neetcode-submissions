class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;
        int n = nums.size();
        int currSum = 0;
        int res = 0;

        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int diff = currSum - k;
            res += prefix_map[diff];
            prefix_map[currSum]++;
        } 
        return res;
    }
};