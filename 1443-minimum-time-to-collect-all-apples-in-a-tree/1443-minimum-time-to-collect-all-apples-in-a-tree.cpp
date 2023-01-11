class Solution {
public:
    int level = 0;
    int ans = 0;
    int timeToCollectApple(vector<vector<int>> &graph, int n, int node, vector<bool> &hasApple, int par){
        int timeToCollect = 0;
        for(auto it : graph[node]){
            if(it != par){
            int timeToCollectFromChild = timeToCollectApple(graph, n, it, hasApple, node);
                if(hasApple[it]){
                    timeToCollect += timeToCollectFromChild + 2;
                    hasApple[node] = true;
                }
            }
        }
        return timeToCollect;
    }
    vector<vector<int>> constructGraph(vector<vector<int>> &edges, int n){
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        
        graph = constructGraph(edges, n);
        
        
        return timeToCollectApple(graph, n, 0, hasApple, -1);
   }
};