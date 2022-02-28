class Solution {
public:
    vector<vector<int>> constructGraph(int n, vector<vector<int>> &edges){
        vector<vector<int>> graphs(n);
        for(auto it: edges){
            int u = it[1];
            int v = it[0];
            graphs[u].push_back(v);
        }
        return graphs;
    }
    bool topoSort(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsvisited, stack<int> &st){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto nbr: graph[node]){
            if(!visited[nbr]){
                if(topoSort(nbr, graph, visited, dfsvisited, st)) return true;
            }
            else if(dfsvisited[nbr]) return true;
        }
        dfsvisited[node] = false;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>&edges) {
        vector<vector<int>> graph = constructGraph(n, edges);
        stack<int> st;
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n, false);
        vector<int> ans;
        for(int currVertex = 0 ; currVertex < n ; currVertex++){
            if(!visited[currVertex]){
                if(topoSort(currVertex, graph, visited, dfsvisited, st)) return ans;
            }
        }
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};