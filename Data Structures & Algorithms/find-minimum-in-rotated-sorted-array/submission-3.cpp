class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        int minNum = nums[0];
        while (left <= right) {
            if (nums[left] < nums[right]) {
                minNum = min(minNum, nums[left]);
                break;
            }
            int mid = (left+right)/2;
            minNum = min(minNum, nums[mid]);
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid-1;
            }
        }
        return minNum;
    }
};
