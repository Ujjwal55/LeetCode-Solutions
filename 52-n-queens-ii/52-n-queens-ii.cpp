class Solution {
public:
    bool isSafe(vector<vector<int>> &board, int n, int row, int col){
        //check in column
        for(int i = row , j = col; i >= 0 ; i--){
            if(board[i][j])
                return false;
        }
        //check in left diagonal
        for(int i = row, j = col ; i>= 0 && j >= 0 ; i--, j--){
            if(board[i][j])
                return false;
        }
        //check in right diagonal
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++){
            if(board[i][j])
                return false;
        }
        return true;
    }
    void printQueens(int n, vector<vector<int>> & board, int i, int j, int &cnt){
        if(i == n){
            cnt++;
            return;
        }
        for(int col = j ; col < n ; col++){
            if(isSafe(board, n, i, col)){
                board[i][col] = 1;
                printQueens(n, board, i+1, j, cnt);
                board[i][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int cnt = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));
        printQueens(n, board, 0, 0, cnt);
        return cnt;
    }
};