class Solution {
public:
    int printWays(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = printWays(m, n, i, j+1, dp) + printWays(m, n, i+1, j, dp);
        
    }
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return printWays(m, n, 0, 0, dp);
    }
};