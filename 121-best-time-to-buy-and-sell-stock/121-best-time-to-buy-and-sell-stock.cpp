class Solution {
public:
    int maxProfit(vector<int> &prices, int n){
        int mini = INT_MAX, profit = 0;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini, prices[i]);
            int diff = prices[i] - mini;
            profit = max(diff, profit);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxProfit(prices, n);
    }
};