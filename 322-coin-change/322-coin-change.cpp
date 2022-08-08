class Solution {
public:
    int minCoins(vector<int> &coins, int sz, int amount, vector<vector<int>> &minimumCoins){
        if(amount == 0) return 0;
        if(sz == 0) return INT_MAX-1;
        if(minimumCoins[sz][amount] != -1) return minimumCoins[sz][amount];
        if(coins[sz-1] <= amount){
            return minimumCoins[sz][amount] = min(1 + minCoins(coins, sz, amount-coins[sz-1], minimumCoins), minCoins(coins, sz-1, amount, minimumCoins));
        }
        else{
            return minimumCoins[sz][amount] = minCoins(coins, sz-1, amount, minimumCoins);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int sz = coins.size();
        vector<vector<int>> minimumCoins(sz+1, vector<int> (amount+1, -1));
        int ans = minCoins(coins, sz, amount, minimumCoins);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};