class Solution {
public:
    void dfs(vector<int>& nums, int depth, vector<int>& curr, vector<bool>& chosen, vector<vector<int>>& res) {
        if (depth == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!chosen[i]) {
                curr.push_back(nums[i]);
                chosen[i] = true;
                dfs(nums, depth+1, curr, chosen, res);
                curr.pop_back();
                chosen[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> chosen(nums.size(), false);
        
        dfs(nums, 0, curr, chosen, res);
        
        return res;
    }
};
