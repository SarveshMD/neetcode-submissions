class Solution {
public:
    int maxCount(unordered_map<char, int>& counts) {
        int m = INT_MIN;
        for (auto& pr: counts) {
            m = max(m, pr.second);
        }
        return m;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0;
        int res = 0;
        for (int right=0; right<s.size(); right++) {
            counts[s[right]]++;
            if (right-left+1 - maxCount(counts) > k) {
                counts[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
