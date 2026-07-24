class Solution {
public:
    string encode(vector<string> &strs)
    {
        string outstring = "";
        for (string& str: strs) {
            outstring += to_string(str.size()) + "#" + str;
        }
        return outstring;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i=0;
        while (i < s.size()) {
            int j = 0;
            while (s[i + j] != '#') {
                j++;
            }
            int strlen = stoi(s.substr(i, j));
            string str = s.substr(i + j + 1, strlen);
            res.push_back(str);
            i = i + j + 1 + strlen;
        }
        return res;

    }
};
