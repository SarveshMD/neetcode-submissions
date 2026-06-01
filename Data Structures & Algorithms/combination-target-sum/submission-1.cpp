class Solution {
public:
    void combinationSumHelp(vector<vector<int>>& sols, vector<int>& currPath, vector<int>& nums, int index, int target) {
        int n = nums.size();
        if (n == index) return;
        if (target == 0) {
            sols.push_back(currPath);
            return;
        }
        // pick
        int target_if_picked = target - nums[index];

        if (target_if_picked >= 0) {
            currPath.push_back(nums[index]);
            combinationSumHelp(sols, currPath, nums, index, target_if_picked);
            currPath.pop_back();
        }
        // don't pick
        combinationSumHelp(sols, currPath, nums, index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> solutions;
        vector<int> currPath;
        combinationSumHelp(solutions, currPath, nums, 0, target);
        return solutions;
    }
};
