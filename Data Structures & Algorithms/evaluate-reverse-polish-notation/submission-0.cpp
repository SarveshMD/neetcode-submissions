class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operators = {"+", "-", "*", "/"};
        for (string s: tokens) {
            if (operators.contains(s)) {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                int res;
                if (s == "+") res = op1+op2;
                else if (s == "-") res = op1-op2;
                else if (s == "*") res = op1*op2;
                else if (s == "/") res = op1/op2;
                stk.push(res);
            }
            else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
