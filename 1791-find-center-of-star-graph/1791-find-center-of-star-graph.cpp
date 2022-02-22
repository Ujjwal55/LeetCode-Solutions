class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        // vector<int> indegree(n+1);
        // vector<int> outdegree(n+1);
        vector<int> degree(n+1, 0);
        // for(int i = 0 ; i < n ; i++){
        //     int v1 = edges[i][0];
        //     int v2 = edges[i][1];
        //     degree[v1]++;
        //     degree[v2]++;
        // }
        for(auto it : edges){
            int v1 = it[0];
            int v2 = it[1];
            degree[v1]++;
            degree[v2]++;
        }
        for(int i = 1 ; i <= n ; i++){
            if(degree[i] == n-1) return i;
        }
        return -1;
    }
};