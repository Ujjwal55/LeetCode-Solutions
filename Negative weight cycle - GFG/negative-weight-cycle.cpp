// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> costs(n, INT_MAX);
	    costs[0] = 0;
	    
	    for(int i = 0 ; i < n-1 ; i++){
	        for(auto edge : edges){
	            int source = edge[0];
	            int dest = edge[1];
	            int weight = edge[2];
	            
	            if(costs[source] != INT_MAX)
	                costs[dest] = min(costs[dest], costs[source] + weight);
	           }
	        }
	    
	    for(auto edge : edges){
	        int source = edge[0];
	        int dest = edge[1];
	        int weight = edge[2];
	        
	        if(costs[source] != INT_MAX && costs[dest] > costs[source] + weight) return 1;
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends