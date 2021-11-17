int dp[46];
class Solution {
public:
    int climbStairs(int n) {
        if(n == 2 || n == 1){
            dp[n] = n;
            return n;
        }
        else if(dp[n] != 0){
            return dp[n];
        }
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }
};
