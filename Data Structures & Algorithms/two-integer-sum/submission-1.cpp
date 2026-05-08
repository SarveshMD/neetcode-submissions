class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i=0; i<nums.size(); i++) {
            int required = target - nums[i];
            if (hashmap.find(required) != hashmap.end()) {
                return vector<int> {hashmap[required], i};
            }
            hashmap[nums[i]] = i;
        }
        return vector<int>{0,0};
    }
};
