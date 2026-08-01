class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operators = {"+", "-", "*", "/"};

        for (string& token: tokens) {
            if (operators.contains(token)) {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                int res;
                if (token == "+") {
                    res = lhs + rhs;
                }
                else if (token == "-") {
                    res = lhs - rhs;
                }
                else if (token == "*") {
                    res = lhs * rhs;
                }
                else if (token == "/") {
                    res = lhs / rhs;
                }
                stk.push(res);
            }
            else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
