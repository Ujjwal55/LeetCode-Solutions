class Solution {
public:
    int minimumSteps(int i, int j, int n, vector<vector<int>> &dp, vector<vector<bool>> &vis){
        if(i > n) return INT_MAX-2;
        if(i == n) return 0;
        if(vis[i][j]){
            return INT_MAX-2;
        }
        else vis[i][j] = true;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = minimumSteps(i, i, n, dp, vis);
        int op2 = minimumSteps(i+j, j, n, dp, vis);
        return dp[i][j] = 1 + min(op1, op2);
     }
    int minSteps(int n) {
        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        vector<vector<bool>> vis(1001, vector<bool>(1001, false));
        return minimumSteps(1, 0, n, dp, vis);
    }
};