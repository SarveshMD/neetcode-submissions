class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;

        for (int i=0; i<nums.size(); i++) {
            if (hashmap[nums[i]] > 0) return nums[i];
            hashmap[nums[i]]++;
        }
        
        return -1;
    }
};
