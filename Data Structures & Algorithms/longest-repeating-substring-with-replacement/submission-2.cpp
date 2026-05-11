class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0;
        int res = 0;
        int maxf = 0;
        for (int right=0; right<s.size(); right++) {
            counts[s[right]]++;
            maxf = max(maxf, counts[s[right]]);
            if (right-left+1 - maxf > k) {
                counts[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
