class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            int temp = temperatures[i];
            if (stk.empty() || temp <= temperatures[stk.top()])
            {
                stk.push(i);
            }
            else
            {
                while (!stk.empty() && temp > temperatures[stk.top()])
                {
                    int top = stk.top();
                    stk.pop();
                    res[top] = i - top;
                }
                stk.push(i);
            }
        }
        return res;
    }
};
