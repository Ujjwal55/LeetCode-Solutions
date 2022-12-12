class Solution {
public:
    vector<vector<pair<int, int>>> constructGraph(vector<vector<int>> &times, int n){
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto it : times){
            int v1 = it[0];
            int v2 = it[1];
            int cost = it[2];
            
            graph[v1].push_back({v2, cost});
        }
        return graph;
    }
    int minTime(vector<vector<pair<int, int>>> &graph, int n, int src){
        vector<int> costs(n+1, INT_MAX);
        costs[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currNode = curr.second;
            int currCost = curr.first;
            
            for(auto it : graph[currNode]){
                int node = it.first;
                int weight = it.second;
                if(currCost + weight < costs[node]){
                    costs[node] = currCost + weight;
                    pq.push({currCost + weight, node});
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(costs[i] == INT_MAX){
                return -1;
            }
        }
        int maxDelay = *max_element(costs.begin()+1, costs.end());
        return maxDelay;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph = constructGraph(times, n);
        return minTime(graph, n, k);
    }
};