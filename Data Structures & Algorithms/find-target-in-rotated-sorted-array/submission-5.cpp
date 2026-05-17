class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m-1;
            else l = m+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) return m;
            if (nums[l] < nums[r]) return binarySearch(nums, target, l, r);
            if (nums[l] <= nums[m]) { // left half sorted, right half rotated
                if (target >= nums[l] && target < nums[m]) {
                    r = m-1;
                }
                else {
                    l = m+1;
                }
            }
            else {
                if (target <= nums[r] && target > nums[m]) {
                    l = m+1;
                }
                else {
                    r = m-1;
                }
            }
        }
        return -1;
    }
};
