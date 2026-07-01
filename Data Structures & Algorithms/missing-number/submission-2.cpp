class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = n;
        for (int i=0; i<n; i++) {
            s += i;
            s -= nums[i];
        }
        return s;
    }
};
