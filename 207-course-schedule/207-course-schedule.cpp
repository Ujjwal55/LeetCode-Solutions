class Solution {
public:
    bool detectCycle(int node, vector<bool> &visited, vector<vector<int>> &graph, vector<bool> &dfsvisited){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto nbr: graph[node]){
            if(!visited[nbr]){
                if(detectCycle(nbr, visited, graph, dfsvisited)) return true;
            }
            else if(dfsvisited[nbr]) return true;
        }
        dfsvisited[node] = false;
        return false;
    }
    vector<vector<int>> constructGraph(int numCourses, vector<vector<int>> &prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites){
            int u = it[1];
            int v = it[0];
            graph[u].push_back(v);
        }
        return graph;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> dfsvisited(numCourses, false);
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                if(detectCycle(i, visited, graph, dfsvisited)) return false;
            }
        }
        return true;
    }
};