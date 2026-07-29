class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        unordered_map<char, int> hashmap;
        int longest = 0;
        hashmap[s[0]]++;
        while (r < n) {
            longest = max(longest, r-l+1);
            r++;
            hashmap[s[r]]++;
            while (hashmap[s[r]] > 1 && l < r) {
                hashmap[s[l]]--;
                l++;
            }
        }
        return longest;
    }
};
