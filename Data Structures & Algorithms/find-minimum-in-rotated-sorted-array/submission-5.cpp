class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];
            int mid = (l+r)/2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return -1;
    }
};
