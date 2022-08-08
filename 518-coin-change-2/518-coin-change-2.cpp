class Solution {
public:
    int numberofWays(vector<int> &coins, int n, int amount, vector<vector<int>> &combinations){
        if(amount == 0) return 1;
        if(n == 0) return 0;
        if(combinations[n][amount] != -1) return combinations[n][amount];
        if(coins[n-1] <= amount){
            return combinations[n][amount] = numberofWays(coins, n, amount-coins[n-1], combinations) + numberofWays(coins, n-1, amount, combinations);
        }
        else return combinations[n][amount] = numberofWays(coins, n-1, amount, combinations);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> combinations(n+1, vector<int> (amount+1, -1));
        return numberofWays(coins, n, amount, combinations);
    }
};