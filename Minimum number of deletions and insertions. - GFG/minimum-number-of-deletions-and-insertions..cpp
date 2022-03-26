// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int longestSubsequence(string str1, string str2, int m, int n){
	    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
	    for(int i = 1 ; i <= m ; i++){
	        for(int j = 1 ; j <= n ; j++){
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    return dp[m][n];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.length();
	    int n = str2.length();
	    int len = longestSubsequence(str1, str2, m, n);
	    return (m + n - 2*len);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends