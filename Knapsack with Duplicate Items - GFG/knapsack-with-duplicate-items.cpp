// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int unbounded(int n, int w, int val[], int wt[], vector<vector<int>> &dp){
        if(n == 0 || w == 0) return 0;
        if(dp[n][w] != -1) return dp[n][w];
        if(wt[n-1] <= w){
            return dp[n][w] = max(val[n-1] + unbounded(n, w-wt[n-1], val, wt, dp),unbounded(n-1, w, val, wt, dp)); 
        }
        else{
            return dp[n][w] = unbounded(n-1, w, val, wt, dp);
        }
    }
    int bottomUp(int n, int w, int val[], int wt[]){
        vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
        for(int i = 0 ; i < n+1 ; i++) dp[i][0] = 0;
        for(int j = 0 ; j < w+1 ; j++) dp[0][j] = 0;
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < w+1 ; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
        // return unbounded(n, w, val, wt, dp);
        return bottomUp(n, w, val, wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends