class Solution {
public:
    void dfs(vector<int>& nums, int target, int index, vector<int>& curr, int curr_sum, vector<vector<int>>& res) {
        if (curr_sum == target) {
            res.push_back(curr);
            return;
        }
        if (index >= nums.size() || curr_sum > target) return;

        dfs(nums, target, index+1, curr, curr_sum, res);
        curr.push_back(nums[index]);
        dfs(nums, target, index, curr, curr_sum + nums[index], res);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, target, 0, curr, 0, res);
        return res;
    }
};
