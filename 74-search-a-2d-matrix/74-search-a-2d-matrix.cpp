class Solution {
public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if(matrix[i][0] <= target and matrix[i][n-1] >= target){
//                     int low = 0, high = n-1;
//                     while(low <= high){
//                         int mid = (low + high) / 2;
//                         if(matrix[i][mid] == target) return true;
//                         else if(matrix[i][mid] < target) low = mid + 1;
//                         else high = mid - 1;
//                     }
//                 }
//             }
//         }
        
//         return false;
//     }
    
//     bool searchMatrix(vector<vector<int>> &matrix, int target){
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int top = 0, bottom = m - 1, row = -1;
//         while(top <= bottom){
//             int mid = (top + bottom) / 2;
//             if(target > matrix[mid][n - 1]) top = mid + 1;
//             else if(target < matrix[mid][0]) bottom = mid - 1;
//             else{
//                 row = mid;
//                 break;
//             }
//         }
        
//         if(row == -1) return false;
//         top = 0, bottom = n - 1;
//         while(top <= bottom){
//             int mid = (top + bottom) / 2;
//             if(target == matrix[row][mid]) return true;
//             if(target > matrix[row][mid]) top = mid + 1;
//             else if(target < matrix[row][mid]) bottom = mid - 1;
//         }
//         return false;
//     }
    
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0, j = n-1;
        while(i < m && j >= 0){
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};