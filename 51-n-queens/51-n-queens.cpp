class Solution {
public:
    bool isValid(vector<string> &s, int n, int row, int col){
        for(int i = row ; i >= 0 ; i--){
            if(s[i][col] == 'Q') return false;
        }
        for(int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--){
            if(s[i][j] == 'Q') return false;
        }
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++){
            if(s[i][j] == 'Q') return false;
        }
        return true;
    }
    void printQueens(vector<vector<string>> &ans, vector<string> &s, int n, int i, int j){
        if(i == n){
            ans.push_back(s);
            return;
        }
        for(int j = 0 ; j < n ; j++){
            if(isValid(s, n, i, j)){
                s[i][j] = 'Q';
                printQueens(ans, s, n, i+1, j);
                s[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> s(n, string(n, '.'));
        printQueens(ans, s, n, 0, 0);
        return ans;
    }
};