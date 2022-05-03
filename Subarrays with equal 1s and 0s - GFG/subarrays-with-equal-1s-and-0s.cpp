// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
        long long int ans = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        
        for(int i = 0 ; i < n ; i++){
            sum += arr[i] == 0 ? -1 : 1;
            if(m.find(sum) != m.end()){
                ans += m[sum];
            }
            m[sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends