class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool is_good = false;
        int earliest_good_index = n-1;
        for (int i=n-1; i>=0; i--) {
            if (i + nums[i] >= earliest_good_index) {
                earliest_good_index = i;
                if (i == 0) is_good = true;
            }
        }
        return is_good;
    }
};
