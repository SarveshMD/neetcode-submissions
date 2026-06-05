class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> good_index(n, 0);
        good_index[n-1] = 1;
        int earliest_good_index = n-1;
        for (int i=n-2; i>=0; i--) {
            if (i + nums[i] >= earliest_good_index) {
                good_index[i] = 1;
                earliest_good_index = i;
            }
        }
        return (bool)good_index[0];
    }
};
