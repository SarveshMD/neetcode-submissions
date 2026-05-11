class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int left = 0;
        int result = 0;
        unordered_set<char> contents;
        for (int right=0; right<n; right++) {
            while (contents.contains(s[right])) {
                contents.erase(s[left]);
                left++;
            }
            contents.insert(s[right]);
            result = max(result, right-left+1);
        }
        return result;
    }
};
