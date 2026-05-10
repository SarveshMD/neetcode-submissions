class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while (left < right) {
            int s = numbers[left] + numbers[right];
            if (s < target) {
                left++;
            }
            else if (s > target) {
                right--;
            }
            else if (s == target) return vector<int> {left + 1, right + 1};
        }
        return vector<int>{-1,-1};
    }
};
