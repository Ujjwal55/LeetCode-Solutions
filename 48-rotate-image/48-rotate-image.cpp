class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //transpose of the matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(i == 0 && j == 0 || i == n-1 && j == n-1) continue;
                else{
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        
        //reverse the columns
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n/2 ; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};