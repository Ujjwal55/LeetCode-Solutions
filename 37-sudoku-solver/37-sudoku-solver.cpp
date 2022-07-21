class Solution {
public:
    bool isValidCell(vector<vector<char>> &board, int currentRow, int currentCol, int currentVal){
        for(int col = 0 ; col < 9 ; col++){
            if(board[currentRow][col] == (currentVal+'0')) return false;
        }
        for(int row = 0 ; row < 9 ; row++){
            if(board[row][currentCol] == (currentVal+'0')) return false;
        }
        int x = 3* (currentRow/3), y = 3* (currentCol/3);
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[x+i][y+j] == (currentVal+'0')) return false;
            }
        }
        return true;
    }
    bool sudokuSolver(vector<vector<char>> &board, int currentRow, int currentCol){
        if(currentRow == 9){
            return true;
        }
        int nextRowpos, nextColpos;
        if(currentCol == 8){
            nextRowpos = currentRow + 1;
            nextColpos = 0;
        }
        else{
            nextRowpos = currentRow;
            nextColpos = currentCol + 1;
        }
        if(board[currentRow][currentCol] != '.'){
            return sudokuSolver(board, nextRowpos, nextColpos);
        }
        for(int currentVal = 1 ; currentVal <= 9 ; currentVal++){
            if(isValidCell(board, currentRow, currentCol, currentVal)){
                board[currentRow][currentCol] = (currentVal+'0');
                if(sudokuSolver(board, nextRowpos, nextColpos)) return true;
                board[currentRow][currentCol] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
        // return;
    }
};