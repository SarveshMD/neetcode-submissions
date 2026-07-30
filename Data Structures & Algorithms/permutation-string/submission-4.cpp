class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> s1_map(26, 0);
        vector<int> s2_map(26, 0);
        for (char c : s1)
        {
            s1_map[c - 'a']++;
        }
        int m = s1.size();
        int n = s2.size();
        if (m > n)
            return false;
        for (int i = 0; i < m; i++)
        {
            s2_map[s2[i] - 'a']++;
        }
        if (s1_map == s2_map) return true;

        int l = 0;
        for (int r = m; r < n; l++, r++)
        {
            s2_map[s2[l] - 'a']--;
            s2_map[s2[r] - 'a']++;
            if (s1_map == s2_map) return true;
        }
        return false;
    }
};
