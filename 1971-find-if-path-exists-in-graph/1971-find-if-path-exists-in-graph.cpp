class Solution {
public:
    bool path(vector<vector<int>> &graph, int source, int destination, vector<bool> &visited){
        if(source == destination) return true;
        visited[source] = true;
        for(auto it : graph[source]){
            if(!visited[it])
                if(path(graph, it, destination, visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto it : edges){
            int v1 = it[0];
            int v2 = it[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        vector<bool> visited(n, false);
        return path(graph, source, destination, visited);
    }
};