class Solution {
public:
    string encode(vector<string> &strs)
    {
        string outString = "";
        for (string str : strs)
        {
            for (char c : str)
            {
                if (c == '\\')
                {
                    outString += "\\\\";
                }
                else
                {
                    outString += c;
                }
            }
            outString += "\\b";
        }
        return outString;
    }

    vector<string> decode(string s)
    {
        vector<string> out;
        string curr = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '\\' && i != s.size() - 1)
            {
                if (s[i + 1] == '\\')
                {
                    i++;
                    curr += "\\";
                }
                else if (s[i + 1] == 'b')
                {
                    i++;
                    out.push_back(curr);
                    curr = "";
                }
            }
            else
            {
                curr += s[i];
            }
        }
        return out;
    }
};
