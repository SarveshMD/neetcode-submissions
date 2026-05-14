class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp = {{')','('}, {'}','{'}, {']','['}};
        unordered_set<char> open = {'(', '{', '['};
        for (char c: s) {
            if (open.contains(c)) {
                st.push(c);
            }
            else {
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
