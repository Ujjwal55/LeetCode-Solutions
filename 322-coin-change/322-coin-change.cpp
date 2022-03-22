class Solution {
public:
    int numberOfCoins(vector<int> &coins, int amount, int n, vector<vector<int>> &dp){
        if(n == 0 || amount == 0){
            return (amount == 0) ? 0 : INT_MAX-1;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        if(coins[n-1] <= amount){
            return dp[n][amount] = min(1 + numberOfCoins(coins, amount-coins[n-1], n, dp), numberOfCoins(coins, amount, n-1, dp));
        }
        else{
            return dp[n][amount] = numberOfCoins(coins, amount, n-1, dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int minCoins = numberOfCoins(coins, amount, n, dp);
        return minCoins == INT_MAX-1 ? -1 : minCoins;
    }
};