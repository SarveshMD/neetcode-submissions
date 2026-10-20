class Solution {
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void fill_substrings(string &s, vector<vector<string>> &substrings, vector<string> &curr, int idx)
    {
        if (idx >= s.size())
        {
            substrings.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                fill_substrings(s, substrings, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> substrings;
        vector<string> curr;
        fill_substrings(s, substrings, curr, 0);
        return substrings;
    }
};
