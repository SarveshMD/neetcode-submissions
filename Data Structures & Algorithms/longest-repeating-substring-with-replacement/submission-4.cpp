class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> hashmap;
        int res = 0;
        while (r < n) {
            hashmap[s[r]]++;
            int winlen = r - l + 1;
            pair<const char, int> best = *max_element(hashmap.begin(), hashmap.end(), 
            [](auto& a, auto& b) {
                return a.second < b.second;
            });
            int remaining_length = winlen - best.second;
            if (remaining_length <= k) {
                res = max(res, winlen);
            }
            else {
                while (remaining_length > k) {
                    hashmap[s[l]]--;
                    l++;
                    winlen = r - l + 1;
                    pair<const char, int> best = *max_element(hashmap.begin(), hashmap.end(), 
                    [](auto& a, auto& b) {
                        return a.second < b.second;
                    });
                    remaining_length = winlen - best.second;
                }
            }
            r++;
        }
        return res;
    }
};
