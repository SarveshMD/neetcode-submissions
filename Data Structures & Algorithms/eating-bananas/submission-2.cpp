class Solution {
public:
    bool isValidK(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile: piles) {
            hours += pile / k;
            if (pile%k != 0) hours++;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int bestValidK = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isValidK(piles, mid, h)) {
                bestValidK = min(right, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return bestValidK;
    }
};
