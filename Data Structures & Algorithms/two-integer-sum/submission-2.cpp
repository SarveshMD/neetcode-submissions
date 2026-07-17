class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int rem = target - nums[i];
            if (hashmap.find(rem) != hashmap.end()) {
                return {hashmap[rem], i};
            }
            else {
                hashmap[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};
