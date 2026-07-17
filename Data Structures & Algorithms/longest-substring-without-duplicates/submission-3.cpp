class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> unique_chars;
        while (right < s.size()) {
            if (!unique_chars.contains(s[right])) {
                unique_chars.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            }
            else {
                while (unique_chars.contains(s[right])) {
                    unique_chars.erase(s[left]);
                    left++;
                }
            }
        }
        return res;
    }
};
