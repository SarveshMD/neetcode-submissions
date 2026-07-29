class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int longest = 0;
        unordered_set<char> hashmap;
        while (r < n) {
            if (hashmap.contains(s[r])) {
                while (l < r && hashmap.contains(s[r])) {
                    hashmap.erase(s[l]);
                    l++;
                }
            }
            else {
                hashmap.insert(s[r]);
                longest = max(longest, r-l+1);
                r++;
            }
        }
        return longest;
    }
};
