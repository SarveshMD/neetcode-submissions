class Solution {
public:
    string together(vector<char>& curr) {
        string res = "";
        for (char c: curr) {
            res += c;
        }
        return res;
    }

    void generate(int n, vector<char>& curr, vector<string>& res, int open, int close) {
        if (open == close && open == n) {
            res.push_back(together(curr));
            return;
        }
        if (open < close) return;
        if ((open+close) >= 2*n) return;

        curr.push_back('(');
        generate(n, curr, res, open+1, close);
        curr.pop_back();
        if (open > close) {
            curr.push_back(')');
            generate(n, curr, res, open, close+1);
            curr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> curr;

        generate(n, curr, res, 0, 0);

        return res;
    }
};
