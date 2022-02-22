// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool checkCycleBFS(int node, int parent, vector<int> adj[], vector<bool> &visited){
      queue<pair<int, int>> q;
      q.push({node, -1});
      visited[node] = true;
      while(!q.empty()){
          auto curr = q.front();
          parent = curr.second;
          node = curr.first;
          q.pop();
          for(auto nbr: adj[curr.first]){
              if(!visited[nbr]){
                  visited[nbr] = true;
                  q.push({nbr, curr.first});
              }
              else if(nbr != parent) return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                if(checkCycleBFS(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends