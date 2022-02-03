class Solution {
public:
    int printPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1000;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(grid[i][j] + printPath(grid, i-1, j, dp), grid[i][j] + printPath(grid, i, j-1, dp));
        return dp[i][j];
    }
    int bottomUp(vector<vector<int>> &grid, int m, int n){
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i > 0){
                        up += dp[i-1][j];
                    }
                    else up += 1000;
                    int left = grid[i][j];
                    if(j > 0){
                        left += dp[i][j-1]; 
                    }
                    else left += 1000;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        // return printPath(grid, m-1, n-1, dp);
        return bottomUp(grid, m, n);
    }
};