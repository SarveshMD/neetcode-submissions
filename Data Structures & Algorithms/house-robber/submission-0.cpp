class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int rob1 = 0, rob2 = nums[0];
        for (int i=1; i<n; i++) {
            int tmp = rob2;
            rob2 = max(rob2, rob1+nums[i]);
            rob1 = tmp;
        }
        return rob2;
    }
};
