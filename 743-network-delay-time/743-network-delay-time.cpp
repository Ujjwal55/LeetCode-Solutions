class Solution {
public:
    vector<vector<pair<int, int>>> constructGraph(vector<vector<int>> &times, int n){
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto edge : times){
            int source = edge[0];
            int dest = edge[1];
            int cost = edge[2];
            graph[source].push_back({dest, cost});
        }
        return graph;
    }
    int minTime(vector<vector<pair<int, int>>> &graph, int n, int src){
        vector<int> costs(n+1, 0);
        vector<bool> visited(n+1, false);
        costs[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currNode = curr.second;
            int currCost = curr.first;
            if(visited[currNode]) continue;
            visited[currNode] = true;
            costs[currNode] = currCost;
            
            for(auto it : graph[currNode]){
                int node = it.first;
                int weight = it.second;
                if(visited[node]) continue;
                pq.push({currCost + weight, node});
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(visited[i] == false) return -1;
        }
        int ans = *max_element(costs.begin(), costs.end());
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph = constructGraph(times, n);
        return minTime(graph, n, k);
    }
};