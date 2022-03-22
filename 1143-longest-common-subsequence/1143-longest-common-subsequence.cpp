class Solution {
public:
    int longestSubsequence(string &s1, string &s2, int m, int n, vector<vector<int>> &dp){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + longestSubsequence(s1, s2, m-1, n-1, dp);
        }
        else{
            return dp[m][n] = max(longestSubsequence(s1, s2, m-1, n, dp), longestSubsequence(s1, s2, m, n-1, dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return longestSubsequence(s1, s2, m, n, dp);
    }
};