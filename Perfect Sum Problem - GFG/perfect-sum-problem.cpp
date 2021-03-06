// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    #define mod 1000000007
	int countOfSubsets(vector<int> &arr, int i, int sum, vector<vector<long long>> &dp){
	   // if(sum < 0) return 0;
	   // if(sum == 0) return 1;
	   // if(i < 0) return 0;
	   // if(i == 0 && sum != 0) return 0;
	   // if(i == 0 and sum == 0) return 1;
	    if(sum == 0) return 1;
	    if(i == 0){
	        return arr[0] == sum;
	    }
	    if(dp[i][sum] != -1) return dp[i][sum];
	    if(arr[i] <= sum){
	        return dp[i][sum] = (countOfSubsets(arr, i-1, sum-arr[i], dp) + countOfSubsets(arr, i-1, sum, dp))%mod;
	    }
	    return dp[i][sum] = countOfSubsets(arr, i-1, sum, dp)%mod; 
	}
	int bottomUp(int arr[], int n, int sum){
	    vector<vector<long long>> dp(n+1, vector<long long> (sum+1, -1));
	    dp[0][0] = 1;
	   
	   // for(int i = 0 ; i <= n ; i++){
	   //     for(int j = 0 ; j <= sum ; j++){
	   //         if(i == 0) dp[i][j] = 0;
	   //         if(j == 0) dp[i][j] = 1;
	   //     }
	   // }
	    for(int j = 1 ; j <= sum ; j++){
	        dp[0][j] = 0;
	    }
	    for(int i = 1 ; i <= n ; i++){
	        for(int j = 0 ; j <= sum ; j++){
	            if(arr[i-1] <= j){
	                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
	            }
	            else{
	                dp[i][j] = dp[i-1][j]%mod;
	            }
	        }
	    }
	    return dp[n][sum];
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    int zero = 0;
	    vector<int> ar;
	    int k = 0;
	    for(int i = 0 ; i < n ; i++){
	        if(arr[i] == 0) zero++;
	        else{
	            ar.push_back(arr[i]);
	            k++;
	        }
	    }
	    vector<vector<long long>> dp(n+1, vector<long long> (sum+1, -1));
	    return pow(2, zero) * countOfSubsets(ar, k-1, sum, dp);
	   //return bottomUp(arr, n-1, sum);
	   
	}
	  
};

	  

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends