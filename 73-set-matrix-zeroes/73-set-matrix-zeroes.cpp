class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows, cols;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(matrix[row][col] == 0){
                    rows.push_back(row);
                    cols.push_back(col);
                }
            }
        }
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(find(rows.begin() ,rows.end(), row) != rows.end()){
                    matrix[row][col] = 0;
                }
                if(find(cols.begin(), cols.end(), col) != cols.end()){
                    matrix[row][col] = 0;
                }
            }
        }
    }
};