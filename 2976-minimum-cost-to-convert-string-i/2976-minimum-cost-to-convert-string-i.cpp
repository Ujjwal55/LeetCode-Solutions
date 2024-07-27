class Solution {
public:
    typedef long long ll;
    
    
    void floydWarshall(vector<vector<ll>> &adjMatrix, vector<char> &original, vector<char> &changed, vector<int> &cost) {
        for(int i = 0 ; i < original.size() ; i++) {
            adjMatrix[original[i] - 'a'][changed[i] - 'a'] = min(adjMatrix[original[i] - 'a'][changed[i] - 'a'], (ll) cost[i]);
        }
        
        for(int k = 0 ; k < 26 ; k++) {
            for(int i = 0 ; i < 26 ; i++) {
                for(int j = 0 ; j < 26 ; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> adjMatrix(26, vector<ll> (26, INT_MAX));
        
        floydWarshall(adjMatrix, original, changed, cost);
        
        ll ans = 0;
        
        for(int i = 0 ; i < source.length() ; i++) {
            if(source[i] == target[i]) continue;
            if(adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        
        return ans;
    }
};