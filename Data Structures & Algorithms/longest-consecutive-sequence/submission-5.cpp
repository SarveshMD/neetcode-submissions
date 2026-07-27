class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hash(nums.begin(), nums.end());
        int longest = 0;
        for (int num: nums) {
            if (hash.contains(num-1)) continue;
            int curr = 1;
            while (hash.contains(num + 1)) {
                num++;
                curr++;
            }
            longest = max(curr, longest);
        }
        return longest;
    }
};
