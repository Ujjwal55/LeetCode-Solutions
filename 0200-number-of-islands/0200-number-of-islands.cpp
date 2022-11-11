class Solution {
public:
    void islands(vector<vector<char>> &grid, int i, int j, int m, int n){
        if(i < 0 || i > m-1 || j < 0 || j > n-1 || grid[i][j] != '1') return;
        grid[i][j] = '0';
        islands(grid, i+1, j, m, n);
        islands(grid, i, j+1, m, n);
        islands(grid, i-1, j, m, n);
        islands(grid, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int currRow = 0 ; currRow < m ; currRow++){
            for(int currCol = 0 ; currCol < n ; currCol++){
                if(grid[currRow][currCol] == '1'){
                    ans++;
                    islands(grid, currRow, currCol, m, n);
                }
            }
        }
        return ans;
    }
};