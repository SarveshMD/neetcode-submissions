class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> num_seqs(nums.begin(), nums.end());
        for (int num: num_seqs) {
            if (num_seqs.contains(num-1)) continue;
            int seq = 1;
            while (num_seqs.contains(num+1)) {
                seq++;
                num++;
            }
            longest = max(seq, longest);
        }
        return longest;
    }
};
