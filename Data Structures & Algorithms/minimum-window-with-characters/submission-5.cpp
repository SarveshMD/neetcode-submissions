class Solution {
public:
    bool validWindow(unordered_map<char, int> &t_hash, unordered_map<char, int> &window_hash)
    {
        for (int i = 0; i < 26; i++)
        {
            if (t_hash['a' + i] > 0 && window_hash['a' + i] < t_hash['a' + i])
                return false;
        }
        for (int i = 0; i < 26; i++)
        {
            if (t_hash['A' + i] > 0 && window_hash['A' + i] < t_hash['A' + i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> t_hash;
        unordered_map<char, int> window_hash;
        int min_window_length = INT_MAX;
        string min_window = "";

        for (char c : t)
        {
            t_hash[c]++;
        }
        int l = 0, r = 0;
        for (; r < n; r++)
        {
            window_hash[s[r]]++;
        }
        if (validWindow(t_hash, window_hash))
        {
            return s.substr(l, r - l);
        }
        while (r < m)
        {
            window_hash[s[r]]++;
            r++;
            while (validWindow(t_hash, window_hash))
            {
                if (r - l < min_window_length)
                {
                    min_window_length = r - l;
                    min_window = s.substr(l, r - l);
                }
                window_hash[s[l]]--;
                l++;
            }
        }
        return min_window;
    }
};
