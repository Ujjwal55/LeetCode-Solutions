// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int minSum(int arr[], int n, int sum1, int sum2, int sum, vector<vector<int>> &dp){
        if(n == 0){
            if(sum1 == sum || sum2 == sum) return INT_MAX;
            return abs(sum1-sum2);
        }
        if(dp[n][sum1] != -1) return dp[n][sum1];
        return dp[n][sum1] = min(minSum(arr, n-1, sum1+arr[n-1], sum2, sum, dp), minSum(arr, n-1, sum1, sum2+arr[n-1], sum ,dp));
    }
	int minDifference(int arr[], int n)  { 
	   int sum = 0;
	   for(int i = 0 ; i < n ; i++) sum+=arr[i];
	   if(n == 1){
	       return sum;
	   }
	   vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	   return minSum(arr, n, 0, 0, sum, dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends