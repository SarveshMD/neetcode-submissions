class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> stk; // stack<pair<int index, int height>>
        for (int i=0; i<n; i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                auto [index, height] = stk.top();
                stk.pop();
                maxArea = max(maxArea, height*(i - index));
                start = index;
            }
            stk.push({start, heights[i]});
        }

        int stk_size = stk.size();
        for (int i=0; i<stk_size; i++) {
            auto pr = stk.top();
            stk.pop();
            maxArea = max(maxArea, pr.second*(n-pr.first));
        }

        return maxArea;

    }
};
