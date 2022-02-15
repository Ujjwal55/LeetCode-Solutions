class Solution {
public:
    void sourcetoTarget(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<bool> &visited, vector<int> &temp, int currNode, int n){
        if(currNode == n-1){
            temp.push_back(currNode);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(visited[currNode] == true) return;
        visited[currNode] = true;
        temp.push_back(currNode);
        for(auto nbr: graph[currNode]){
            sourcetoTarget(graph, ans, visited, temp, nbr, n);
        }
        visited[currNode] = false;
        temp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> temp;
        sourcetoTarget(graph, ans, visited, temp, 0, n);
        return ans;
    }
};