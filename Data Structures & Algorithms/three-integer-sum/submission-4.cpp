class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            while (left < right) {
                if (left > i+1 && nums[left] == nums[left-1]) {
                    left++;
                    continue;
                }
                if (right < n - 1 && nums[right] == nums[right+1]) {
                    right--;
                    continue;
                }
                int curr = nums[left] + nums[right];
                if (curr == target) {
                    sol.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (curr < target) left++;
                else right--;
            }
        }
        return sol;
    }
};
