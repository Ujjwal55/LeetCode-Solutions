class Solution {
public:
    vector<vector<int>> createGraph(int numCourses, vector<vector<int>> &prerequisites){
        vector<vector<int>> graph(numCourses);
        
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        return graph;
    }
    bool isCycle(int numCourses, vector<vector<int>> &graph){
        vector<int> indegree(numCourses, 0);
        for(int i = 0 ; i < numCourses ; i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans++;
            for(auto neigh : graph[curr]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        if(ans == numCourses) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        return isCycle(numCourses, graph);
    }
};