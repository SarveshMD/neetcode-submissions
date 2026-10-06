class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int new_slow = 0;
        while (new_slow != slow) {
            slow = nums[slow];
            new_slow = nums[new_slow];
        }

        return new_slow;
    }
};
