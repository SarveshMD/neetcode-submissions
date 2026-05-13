class Solution {
public:
    string minWindow(string s, string t)
    {
        if (t == "")
            return "";

        unordered_map<char, int> countT, window;

        for (char c : t)
        {
            countT[c]++;
        }

        int resL = -1, resR = -1;
        int resLen = INT_MAX;

        int have = 0;
        int need = t.size();

        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if (window[c] <= countT[c])
                have++;

            while (have == need)
            {
                if (r - l + 1 < resLen)
                {
                    resLen = r - l + 1;
                    resL = l;
                    resR = r;
                }
                window[s[l]]--;
                if (window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        return ((resLen != INT_MAX)?s.substr(resL, resLen):"");
    }
};
