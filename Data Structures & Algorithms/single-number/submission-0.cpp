class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int runningXOR = 0;
        for (int num: nums) {
            runningXOR ^= num;
        }
        return runningXOR;
    }
};
