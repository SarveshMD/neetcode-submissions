class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target)  {
                    sol.push_back({-target, nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left-1] && left < right)
                        left++;
                }
                else if (sum < target) left++;
                else right--;
            }
        }
        return sol;
    }
};
