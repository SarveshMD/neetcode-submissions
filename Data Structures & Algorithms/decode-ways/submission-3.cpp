class Solution {
public:
    int decode(string s, int k, vector<int> &dp)
    {
        if (s.size() <= k)
            dp[k] = 1;
        if (s[k] == '0')
            dp[k] = 0;
        if (dp[k] != -1)
            return dp[k];
        int res = decode(s, k + 1, dp);
        string sub = s.substr(k, 2);
        if (sub.size() >= 2 && stoi(sub) <= 26)
        {
            res += decode(s, k + 2, dp);
        }
        dp[k] = res;
        return res;
    }

    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return decode(s, 0, dp);
    }
};
