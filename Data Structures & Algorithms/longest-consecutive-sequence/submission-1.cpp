class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        for (int i=0; i<nums.size(); i++) {
            if (num_set.contains(nums[i]-1)) continue;
            int seq = 1;
            int next_num = nums[i]+1;
            while (num_set.contains(next_num)) {
                seq++;
                next_num++;
            }
            if (seq > longest) longest = seq;
        }
        return longest;
    }
};
