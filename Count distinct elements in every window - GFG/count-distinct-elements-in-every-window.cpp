// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        int distinctCount = 0;
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0 ; i < k ; i++){
            if(m.find(a[i]) == m.end()) distinctCount++;
            m[a[i]]++;
        }
        ans.push_back(distinctCount);
        
        for(int i = k ; i < n ; i++){
            m[a[i-k]]--;
            if(m[a[i-k]] == 0) distinctCount--;
            if(m.find(a[i]) == m.end() || m[a[i]] == 0) distinctCount++;
            m[a[i]]++;
            ans.push_back(distinctCount);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends