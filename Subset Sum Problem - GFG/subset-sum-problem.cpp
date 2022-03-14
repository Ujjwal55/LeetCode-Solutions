// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool subsetSum(int arr[], int n, int sum, vector<vector<int>> &dp){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(arr[n-1] <= sum){
        return dp[n][sum] = subsetSum(arr, n-1, sum-arr[n-1], dp)|| subsetSum(arr, n-1, sum, dp);
    }
    return dp[n][sum] = subsetSum(arr, n-1, sum, dp);
}
    bool isSubsetSum(int n, int arr[], int sum){
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return subsetSum(arr, n, sum, dp);
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends