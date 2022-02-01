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
    int tabulation(int m, int n){
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i == m-1 && j == n-1) dp[i][j] = 1;
                else{
                    int right = 0;
                    int down = 0;
                    if(j < n-1){
                        right = dp[i][j+1];
                    }
                    if(i < m-1){
                        down = dp[i+1][j];
                    }
                    dp[i][j] = right + down;
                }
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int> (n, -1));
        // return printWays(m, n, 0, 0, dp);
        return tabulation(m, n);
    }
};