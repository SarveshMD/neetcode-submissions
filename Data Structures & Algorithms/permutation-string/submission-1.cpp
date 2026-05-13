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
        int matches = 0;
        for (int i = 0; i < 26; i++)
        {
            char p = 'a' + i;
            if (s1_counts[p] == s2_counts[p])
                matches++;
        }
        cout << matches << endl;
        for (int l = 0; l <= m - n; l++)
        {
            if (matches == 26)
                return true;
            if (l == m - n)
                break;
            char c = s2[l];
            if (s1_counts[c] == s2_counts[c])
                matches--;
            s2_counts[c]--;
            if (s1_counts[c] == s2_counts[c])
                matches++;
            c = s2[l + n];
            if (s1_counts[c] == s2_counts[c])
                matches--;
            s2_counts[c]++;
            if (s1_counts[c] == s2_counts[c])
                matches++;
        }
        return false;
    }
};
