class Solution {
public:
    void surrounded(vector<vector<char>> &board, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = 'A';
        surrounded(board, i+1, j, m, n);
        surrounded(board, i, j+1, m, n);
        surrounded(board, i-1, j, m, n);
        surrounded(board, i, j-1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O'){
                surrounded(board, i, 0, m, n);
            }
            if(board[i][n-1] == 'O'){
                surrounded(board, i, n-1, m ,n);
            }
        }
        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O'){
                surrounded(board, 0, j, m, n);
            }
            if(board[m-1][j] == 'O'){
                surrounded(board, m-1, j, m, n);
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};