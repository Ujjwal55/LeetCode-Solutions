class Solution {
public:
    int decode(string &s, int i, vector<int> &dp){
        if(i < 0) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 0, op2 = 0;
        int op1 = s[i] - '0';
        if(i > 0){
            op2 = (s[i-1]-'0')*10 + op1;
        }
        if(op1 > 0) ans += decode(s, i-1, dp);
        if(op2 >= 10 && op2 <= 26) ans += decode(s, i-2, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        int ans = decode(s, n-1, dp);
        return ans;
    }
};