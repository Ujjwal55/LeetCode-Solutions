// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        vector<bool> visited(V, false);
        vector<int> costs(V, 0);
        int ans = 0;
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currNode = curr.second;
            int currCost = curr.first;
            if(visited[currNode]) continue;
            
            visited[currNode] = true;
            costs[currNode] = currCost;
            
            for(auto it : adj[currNode]){
                int node = it[0];
                int cost = it[1];
                if(visited[node]) continue;
                pq.push({cost, node});
            }
        }
        for(auto it : costs){
            ans+=it;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends