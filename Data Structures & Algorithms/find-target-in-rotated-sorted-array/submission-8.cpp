class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) return m;
            else if (target < nums[m]) r = m-1;
            else l = m+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        if (nums[l] <= nums[r]) return binarySearch(nums, l, r, target);

        while (l <= r) {
            int m = (l+r)/2;
            if (m+1 <= r && nums[m] > nums[m+1]) {
                int res = binarySearch(nums, 0, m, target);
                if (res == -1) return binarySearch(nums, m+1, n-1, target);
                else return res;
            }
            else if (nums[m] < nums[r]) {
                r = m;
            }
            else if (nums[m] > nums[r]) {
                l = m+1;
            }
        }
        return -1;
    }
};
