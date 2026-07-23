class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i=0; i<nums.size(); i++) {
            if (hashmap.contains(target - nums[i])) {
                return {hashmap[target - nums[i]], i};
            }
            hashmap[nums[i]] = i;
        }
        return {0, 0};
    }
};
