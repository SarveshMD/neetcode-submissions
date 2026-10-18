class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& curr, int idx, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        curr.push_back(nums[idx]);
        dfs(nums, curr, idx+1, res);
        curr.pop_back();
        while (idx+1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }
        dfs(nums, curr, idx+1, res);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> curr;
        
        dfs(nums, curr, 0, res);

        return res;
    }
};
