class Solution {
public:
    unordered_map<int, vector<char>> keymap = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}};

    string tie_together(vector<char> &vector_of_char)
    {
        string res = "";
        for (char c : vector_of_char)
        {
            res += c;
        }
        return res;
    }

    void backtrack(string &digits, int idx, vector<string> &res, vector<char> &curr)
    {
        if (idx >= digits.size())
        {
            if (!curr.empty())
                res.push_back(tie_together(curr));
            return;
        }

        for (char c : keymap[digits[idx] - '0'])
        {
            curr.push_back(c);
            backtrack(digits, idx + 1, res, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        vector<char> curr;

        backtrack(digits, 0, res, curr);

        return res;
    }
};
