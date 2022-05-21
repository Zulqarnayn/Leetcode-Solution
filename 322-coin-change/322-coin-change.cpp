class Solution {
public:
    vector<vector<int>> dp;
    
    int calculateMinimumCoins(int idx, vector<int>& coins, int amount) {
        if(idx >= coins.size()) return INT_MAX - 2;
        if(amount < 0) return INT_MAX - 2;
        if(amount == 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int minCoinCount = INT_MAX - 2;
        
        //by taking this coin
        minCoinCount = min(minCoinCount, 1 + calculateMinimumCoins(idx, coins, amount - coins[idx]));
        //& don't taking this coin
        minCoinCount = min(minCoinCount, calculateMinimumCoins(idx + 1, coins, amount));
        
        return dp[idx][amount] = minCoinCount;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int> (amount + 1, -1));
        int result = calculateMinimumCoins(0, coins, amount);
        
        return result == INT_MAX - 2 ?  -1 : result;
    }
};