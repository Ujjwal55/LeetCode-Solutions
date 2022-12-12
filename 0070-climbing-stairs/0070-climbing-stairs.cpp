class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1);
        int ans = 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            ans = dp[i-1] + dp[i-2];
            dp[i] = ans;
        }
        return dp[n];
    }
};