class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left = 0, right=1;
        while (right < prices.size()) {
            int profit = prices[right]-prices[left];
            if (profit > 0) {
                maxProfit = max(maxProfit, profit);
                right++;
            }
            else {
                left=right;
                right++;
            }
        }
        return maxProfit;
    }
};
