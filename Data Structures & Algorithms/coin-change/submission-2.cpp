class Solution {
public:
    int change(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
        {
            dp[amount] = 0;
            return 0;
        }
        if (dp[amount] != -1)
            return dp[amount];
        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int remaining = amount - coin;
            if (remaining < 0)
                continue;
            int ans = change(coins, remaining, dp);
            if (ans != INT_MAX)
                minCoins = min(minCoins, ans);
        }
        if (minCoins == INT_MAX)
        {
            dp[amount] = INT_MAX;
            return INT_MAX;
        }
        else
        {
            dp[amount] = 1 + minCoins;
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int res = change(coins, amount, dp);
        return (res != INT_MAX ? res : -1);
    }

};
