class Solution {
public:
    int calculateTribonacci(int n, vector<int> &dp){
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = calculateTribonacci(n-1, dp) + calculateTribonacci(n-2, dp) + calculateTribonacci(n-3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return calculateTribonacci(n, dp);
    }
};