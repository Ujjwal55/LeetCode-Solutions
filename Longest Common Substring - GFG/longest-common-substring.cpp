// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    // int longestSubstring(string s1, string s2, int n, int m, int count, vector<vector<vector<int>>> &dp){
    //     if(n == 0 || m == 0) return count; 
    //     if(dp[n][m][count] != -1) return dp[n][m][count];
        
    //     if(s1[n-1] == s2[m-1]){
    //         count = longestSubstring(s1, s2, n-1, m-1, count+1, dp);
    //     }
    //     int c1 = longestSubstring(s1, s2, n-1, m, 0, dp);
    //     int c2 = longestSubstring(s1, s2, n, m-1, 0, dp);
    //     return dp[n][m][count] = max(count, max(c1, c2));
    // }
    // int bottomUp(string s1, string s2, int n, int m){
    //     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    //     int ans = 0;
    //     for(int i = 1 ; i <= n ; i++){
    //         for(int j = 1 ; j <= m ; j++){
    //             if(s1[i-1] == s2[j-1]){
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //                 ans = max(ans, dp[i][j]);
    //             }
    //             else{
    //                 dp[i][j] = 0;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // int longestCommonSubstr (string s1, string s2, int n, int m)
    // {
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (min(n, m)+1, -1)));
    //     return longestSubstring(s1, s2, n, m, 0, dp);
    //     // return bottomUp(s1, s2, n, m);
    // }
    int ans;
int dp[1001][1001];
int helper(string &a, string &b, int n, int m){
  if(n==0 || m==0){
    return 0;
  }
  if(dp[n][m]!=-1){
    return dp[n][m];
  }
  helper(a, b, n, m-1);
  helper(a, b, n-1, m);
  if(a[n-1]==b[m-1]){
    int ret=1+helper(a, b, n-1, m-1);
    ans=max(ans, ret);
    return dp[n][m]=ret;
  }
  return dp[n][m]=0;
}
int longestCommonSubstr(string a, string b, int n, int m){
  memset(dp, -1, sizeof(dp));
  ans=INT_MIN;
  helper(a, b, n, m);
   return ans==INT_MIN?0:ans;
}
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends