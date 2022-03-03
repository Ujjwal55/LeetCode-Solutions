class Solution {
public:
    int numberofIslands(vector<vector<int>> &grid, int row, int col, int m, int n){
        if(row > m-1 || col > n-1 || row < 0 || col < 0 || grid[row][col] != 0) return 0;
        if(row == 0 || col == 0 || row == m-1 || col == n-1) return 1;
        grid[row][col] = 2;
        int a = numberofIslands(grid, row, col+1, m, n);
        int b = numberofIslands(grid, row+1, col, m, n);
        int c = numberofIslands(grid, row, col-1, m, n);
        int d = numberofIslands(grid, row-1, col, m, n);
        return a+b+c+d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0){
                    if(numberofIslands(grid, row, col, m, n) == 0) ans++;
                }
            }
        }
        return ans;
    }
};