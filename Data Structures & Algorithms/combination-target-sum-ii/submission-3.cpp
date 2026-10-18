class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, int curr_sum, int index, vector<vector<int>>& res) {
        if (curr_sum == target) {
            res.push_back(curr);
            return;
        }
        if (index >= candidates.size() || curr_sum > target) return;

        curr.push_back(candidates[index]);
        dfs(candidates, target, curr, curr_sum+candidates[index], index+1, res);
        curr.pop_back();
        while (index+1 < candidates.size() && candidates[index] == candidates[index+1]) {
            index++;
        }
        dfs(candidates, target, curr, curr_sum, index+1, res);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        dfs(candidates, target, curr, 0, 0, res);

        return res;
    }
};
