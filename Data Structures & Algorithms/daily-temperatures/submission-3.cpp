class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n, 0);
        for (int i=0; i<n; i++) {
            if (stk.empty() || temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    int index = stk.top();
                    res[index] = i - index;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};
