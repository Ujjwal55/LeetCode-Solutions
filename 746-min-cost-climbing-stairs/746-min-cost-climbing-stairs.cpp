class Solution {
public:
    int printCost(vector<int> &cost, int n, int i, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int price = cost[i] + printCost(cost, n, i+1, dp);
        if(i+2 <= n)
            price = min(price, cost[i]+ printCost(cost, n, i+2, dp));
        return dp[i] = price;
    }
    int bottomUp(vector<int> &cost, int n, vector<int> &dp){
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, -1);
        // return min(printCost(cost, n, 0, dp), printCost(cost, n, 1, dp));
        return bottomUp(cost, n, dp);
    }
};