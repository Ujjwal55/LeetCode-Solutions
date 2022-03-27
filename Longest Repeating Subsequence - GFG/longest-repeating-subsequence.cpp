// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
		int LongestRepeatingSubsequence(string str){
		    int m = str.length();
		    string t = str;
		    vector<vector<int>> dp(m+1, vector<int> (m+1, 0));
		    for(int  i = 1 ; i <= m ; i++){
		        for(int j = 1 ; j<= m ; j++){
		            if(str[i-1] == t[j-1] && i != j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[m][m];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends