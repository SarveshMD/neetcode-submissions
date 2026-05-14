class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            int temp = temperatures[i];
            if (stk.empty() || temp <= stk.top().first)
            {
                stk.push({temp, i});
            }
            else
            {
                while (!stk.empty() && temp > stk.top().first)
                {
                    pair<int, int> item = stk.top();
                    stk.pop();
                    res[item.second] = i - item.second;
                }
                stk.push({temp, i});
            }
        }
        return res;
    }
};
