class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> leftBound(n, -1);
        vector<int> rightBound(n, n);
        stack<int> stk;

        for (int i=0; i<n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (!stk.empty()) leftBound[i] = stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i=n-1; i>=0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            if (!stk.empty()) rightBound[i] = stk.top();
            stk.push(i);
        }

        int res = 0;

        for (int i=0; i<n; i++) {
            int width = rightBound[i] - leftBound[i] - 1;
            res = max(res, width*heights[i]);
        }
        return res;
    }
};
