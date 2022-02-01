class Solution {
public:
    int printPaths(vector<vector<int>> &obstacleGrid, int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i > m-1 || j > n-1 || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = printPaths(obstacleGrid, m, n, i+1, j, dp) + printPaths(obstacleGrid, m, n, i, j+1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return printPaths(obstacleGrid, m, n, 0, 0, dp);
    }
};