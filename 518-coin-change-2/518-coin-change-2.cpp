class Solution {
public:
    int maxWays(vector<int> &coins, int amount, int n, vector<vector<int>> &dp){
        if(n == 0 || amount == 0){
            return (amount == 0) ? 1 : 0;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        if(coins[n-1] <= amount){
            return dp[n][amount] = maxWays(coins, amount-coins[n-1], n, dp) + maxWays(coins, amount, n-1, dp);
        }
        else{
            return dp[n][amount] = maxWays(coins, amount, n-1, dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        return maxWays(coins, amount, n, dp);
    }
};