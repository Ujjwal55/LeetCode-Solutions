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
    void fillBFS(vector<vector<char>> &grid, int m, int n, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row < 0 || curr_row > m-1 || curr_col < 0 || curr_col > n-1 || grid[curr_row][curr_col] == '0') continue;
            grid[curr_row][curr_col] = '0';
            q.push({curr_row, curr_col+1});
            q.push({curr_row+1, curr_col});
            q.push({curr_row, curr_col-1});
            q.push({curr_row-1, curr_col});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == '1'){
                    ans+=1;
                    // fill(grid, m, n, row, col);
                    fillBFS(grid, m, n, row, col);
                }
            }
        }
        return ans;
    }
};