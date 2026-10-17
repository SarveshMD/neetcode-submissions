class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, int currSum, int index, vector<vector<int>>& res, bool was_last_selected) {
        if (target == currSum) {
            res.push_back(curr);
            return;
        }        
        if (index >= candidates.size() || currSum > target) return;
        if (index != 0 && candidates[index-1] == candidates[index] && !was_last_selected) {
            dfs(candidates, target, curr, currSum, index+1, res, false);
            return;
        }

        dfs(candidates, target, curr, currSum, index+1, res, false);
        curr.push_back(candidates[index]);
        dfs(candidates, target, curr, currSum + candidates[index], index+1, res, true);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        dfs(candidates, target, curr, 0, 0, res, false);
        
        return res;
    }
};
