class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i=0; i<nums.size(); i++) {
            int required = target - nums[i];
            if (hashmap[required]) {
                return vector<int> {hashmap[required]-1, i};
            }
            hashmap[nums[i]] = i+1;
        }
        return vector<int>{0,0};
    }
};
