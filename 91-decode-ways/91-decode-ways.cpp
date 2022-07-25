class Solution {
public:
    int decode(string &s, int i, int n, vector<int> &dp){
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        int op1 = s[i] - '0';
        int op2 = 0, ans = 0;
        if(i < n-1){
            op2 = op1*10 + s[i+1] - '0';
        }
        if(op1 > 0) ans += decode(s, i+1, n, dp);
        if(op2 >= 10 && op2 <= 26) ans += decode(s, i+2, n, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        int ans = decode(s, 0, n ,dp);
        return ans;
    }
};