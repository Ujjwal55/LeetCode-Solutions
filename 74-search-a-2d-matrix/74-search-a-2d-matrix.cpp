class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][0] <= target and matrix[i][n-1] >= target){
                    int low = 0, high = n-1;
                    while(low <= high){
                        int mid = (low + high) / 2;
                        if(matrix[i][mid] == target) return true;
                        else if(matrix[i][mid] < target) low = mid + 1;
                        else high = mid - 1;
                    }
                }
            }
        }
        
        return false;
    }
};