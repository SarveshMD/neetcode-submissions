class Solution {
public:
    void backtrack(int i, vector<int>& curr, vector<vector<int>>& res, vector<int>& nums) {
        if (i == nums.size()) res.push_back(curr);
        if (i >= nums.size()) return;
        backtrack(i+1, curr, res, nums);
        curr.push_back(nums[i]);
        backtrack(i+1, curr, res, nums);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, curr, res, nums);
        return res;
    }
};
