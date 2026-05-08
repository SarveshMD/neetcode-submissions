class Solution {
public:
    string encode(vector<string> &strs)
    {
        string outString = "";
        for (string str : strs)
        {
            outString += to_string(str.size()) + "#" + str;
        }
        return outString;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.size())
        {
            int j = 0;
            while (s[i + j] != '#')
            {
                j++;
            }
            int len = stoi(s.substr(i, j));
            res.push_back(s.substr(i + j + 1, len));
            i += j + len + 1;
        }
        return res;
    }
};
