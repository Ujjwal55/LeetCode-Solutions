// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    #define mod 1000000007
	int countOfSubsets(int arr[], int i, int sum, vector<vector<long long>> &dp){
	   // if(sum < 0) return 0;
	   // if(sum == 0) return 1;
	    if(i < 0) return 0;
	    if(i == 0 && sum != 0) return 0;
	    if(i == 0 and sum == 0) return 1;
	    if(dp[i][sum] != -1) return dp[i][sum];
	    if(arr[i-1] <= sum){
	        return dp[i][sum] = (countOfSubsets(arr, i-1, sum-arr[i-1], dp) + countOfSubsets(arr, i-1, sum, dp))%mod;
	    }
	    return dp[i][sum] = countOfSubsets(arr, i-1, sum, dp)%mod; 
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<long long>> dp(n+1, vector<long long> (sum+1, -1));
	    return countOfSubsets(arr, n, sum, dp);
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