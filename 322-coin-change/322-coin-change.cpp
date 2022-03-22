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
    int bottomUp(vector<int> &coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= amount ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = (i == 0) ? INT_MAX-1 : 0;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        // int minCoins = numberOfCoins(coins, amount, n, dp);
        int minCoins = bottomUp(coins, amount);
        return minCoins == INT_MAX-1 ? -1 : minCoins;
    }
};