class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {{')','('}, {'}','{'}, {']','['}};
        unordered_set<char> open = {'(', '{', '['};
        stack<char> stk;
        for (char c: s) {
            if (open.contains(c)) {
                stk.push(c);
            }
            else if (mp.contains(c)) {
                if (stk.empty() || stk.top() != mp[c]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
