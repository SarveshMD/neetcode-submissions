class Solution {
public:
    int rob0(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = nums[start];
        for (int i=start+1; i<end; i++) {
            int tmp = rob2;
            rob2 = max(rob2, rob1+nums[i]);
            rob1 = tmp;
        }
        return rob2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums[0];
        return max(rob0(nums, 0, n-1), rob0(nums, 1, n));
    }
};
