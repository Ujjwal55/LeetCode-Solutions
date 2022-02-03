class Solution {
public:
    int printPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1000;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(grid[i][j] + printPath(grid, i-1, j, dp), grid[i][j] + printPath(grid, i, j-1, dp));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return printPath(grid, m-1, n-1, dp);
    }
};