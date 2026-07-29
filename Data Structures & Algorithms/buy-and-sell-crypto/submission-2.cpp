class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int leftMin = prices[0];
        int bestProfit = 0;
        for (int i=1; i<n; i++) {
            bestProfit = max(bestProfit, prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        return bestProfit;
    }
};
