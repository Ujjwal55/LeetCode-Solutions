class Solution {
public:
    int getDistance(vector<int> &v1, vector<int> &v2){
        return (abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                graph[i].push_back({j, getDistance(points[i], points[j])});
                graph[j].push_back({i, getDistance(points[i], points[j])});
            }
        }
        vector<bool> visited(n, false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currNode = it.second;
            int currCost = it.first;
            
            if(visited[currNode]) continue;
            visited[currNode] = true;
            ans += currCost;
            
            for(auto nbr : graph[currNode]){
                int node = nbr.first;
                int cost = nbr.second;
                if(visited[node]) continue;
                pq.push({cost, node});
            }
        }
        return ans;
    }
};