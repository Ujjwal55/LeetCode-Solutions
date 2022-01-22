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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(printCost(cost, n, 0, dp), printCost(cost, n, 1, dp));
    }
};