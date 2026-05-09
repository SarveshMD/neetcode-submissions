class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        for (int val: num_set) {
            if (num_set.contains(val-1)) continue;
            int seq = 1;
            int next_num = val+1;
            while (num_set.contains(next_num)) {
                seq++;
                next_num++;
            }
            if (seq > longest) longest = seq;
        }
        return longest;
    }
};
