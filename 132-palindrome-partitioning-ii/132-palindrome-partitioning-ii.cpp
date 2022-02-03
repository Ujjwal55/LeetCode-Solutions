class Solution {
public:
    int minimumCuts(string &s, int start, int end, vector<vector<int>> &dp){
        if(start >= end || isPalindrome(s, start, end)) return 0;
        int ans = 100000;
        if(dp[start][end] != -1) return dp[start][end];
        for(int i = start ; i < end ; i++){
            if(isPalindrome(s, start, i)){
                int tempAns = minimumCuts(s, i+1, end, dp) + 1;
                ans = min(ans, tempAns);
            }
        }
        return dp[start][end] = ans;
    }
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return minimumCuts(s, 0, n-1, dp);
    }
};