class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        stack<int> stk;
        unordered_map<int, int> tmp_res;
        for (int i=0; i<n; i++) {
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                int idx = stk.top();
                tmp_res[nums2[idx]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            tmp_res[nums2[stk.top()]] = -1;
            stk.pop();
        }
        vector<int> res(m, -1);
        for (int i=0; i<m; i++) {
            res[i] = tmp_res[nums1[i]];
        }
        return res;
    }
};