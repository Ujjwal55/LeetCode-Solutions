class Solution {
public:
    vector<vector<int>> constructGraph(int numCourses, vector<vector<int>> &prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        return graph;
    }
    bool order(vector<vector<int>> &graph, int node, vector<int> &visited, vector<int> &dfsvisited, vector<int> &result){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto neigh : graph[node]){
            if(!visited[neigh]){
                if(order(graph, neigh, visited, dfsvisited, result)) return true;
            }
            else if(dfsvisited[neigh]) return true;
        }
        dfsvisited[node] = false;
        result.push_back(node);
        return false;        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = constructGraph(numCourses, prerequisites);
        vector<int> visited(numCourses, false);
        vector<int> dfsvisited(numCourses, false);
        vector<int> ans;
        vector<int> result;
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                if(order(graph, i, visited, dfsvisited, result)) return ans;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};