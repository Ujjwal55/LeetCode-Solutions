class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row = mat[0];
        
        for(int i = 1 ; i < n ; i++){
            vector<int> temp;
            for(int j = 0 ; j < m ; j++){
                for(auto it : row){
                    temp.push_back(it+mat[i][j]);
                }
            }
            sort(temp.begin(), temp.end());
            row.resize(min(k, int(temp.size())));
            for(int i = 0 ; i < min(k, int(temp.size())) ; i++){
                row[i] = temp[i];
            }
        }
        return row[k-1];
    }
};