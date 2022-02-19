class Solution {
public:
    void fill(vector<vector<char>> &grid, int m, int n, int row, int col){
        if(row < 0 || row > m-1 || col < 0 || col > n-1 || grid[row][col] == '0') return;
        grid[row][col] = '0';
        fill(grid, m, n, row, col+1);
        fill(grid, m, n, row+1, col);
        fill(grid, m, n, row, col-1);
        fill(grid, m, n, row-1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == '1'){
                    ans+=1;
                    fill(grid, m, n, row, col);
                }
            }
        }
        return ans;
    }
};