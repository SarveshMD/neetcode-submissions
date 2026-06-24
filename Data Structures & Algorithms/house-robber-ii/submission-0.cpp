class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxRob = 0;
        int rob1 = 0, rob2 = nums[0];
        for (int i=1; i<n-1; i++) {
            int tmp = rob2;
            rob2 = max(rob2, rob1+nums[i]);
            rob1 = tmp;
        }
        maxRob = rob2;
        if (n < 2) return maxRob;
        rob1 = 0;
        rob2 = nums[1];
        for (int i=2; i<n; i++) {
            int tmp = rob2;
            rob2 = max(rob2, rob1 + nums[i]);
            rob1 = tmp;
        }
        maxRob = max(maxRob, rob2);
        return maxRob;
    }
};
