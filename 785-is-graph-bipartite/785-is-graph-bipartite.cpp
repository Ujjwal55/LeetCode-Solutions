class Solution {
public:
    bool hasEvenLengthCycle(int node, vector<vector<int>> &graph, int color, vector<int> &colors){
        if(colors[node] != -1){
            return colors[node] == color;
        }
        colors[node] = color;
        for(auto nbr: graph[node]){
            if(!hasEvenLengthCycle(nbr, graph, 1-color, colors)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i = 0 ; i < n ; i++){
            if(colors[i] == -1){
                if(!hasEvenLengthCycle(i, graph, 0, colors)) return false;
            }
        }
        return true;
    }
};