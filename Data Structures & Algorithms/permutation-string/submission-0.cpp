class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        if (n > m)
            return false;
        unordered_map<char, int> s1_counts;
        unordered_map<char, int> s2_counts;
        for (char c : s1)
        {
            s1_counts[c]++;
        }
        for (int i = 0; i < n; i++)
        {
            s2_counts[s2[i]]++;
        }
        for (int l = 0; l <= m - n; l++)
        {
            if (s1_counts == s2_counts)
                return true;
            if (l == m - n)
                break;
            s2_counts[s2[l]]--;
            if (s2_counts[s2[l]] == 0)
                s2_counts.erase(s2[l]);
            s2_counts[s2[l + n]]++;
        }
        return false;
    }
};
