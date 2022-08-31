class Solution {
    private:
    vector<pair<int,int>> m_directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    using Matrix = vector<vector<int>>;
    using Visited = vector<vector<bool>>;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      if(matrix.empty()) return {};
      int rows = matrix.size(), cols = matrix[0].size();
     
      vector<vector<int>> res;
      Visited pacific(rows,vector<bool>(cols,false));
      Visited atlantic(rows,vector<bool>(cols,false));
      
     for(int x = 0; x < rows; ++x) {          
          dfs(matrix, pacific, x, 0);
          dfs(matrix, atlantic,x, cols-1);
      }  
     
      for(int y = 0; y < cols; ++y) {
          dfs(matrix,pacific,0,y);
          dfs(matrix,atlantic,rows-1,y);
          
      }
    
    for(int x = 0; x < rows; ++x)
        for(int y = 0; y < cols; ++y) {
            if(pacific[x][y] && atlantic[x][y])
                res.push_back(vector<int>{x,y});
        }
        
        return res;
        
    }
    
    void dfs( Matrix & matrix, Visited & visited, int x, int y ) {
        if(visited[x][y]) return;
         visited[x][y] = true;
        for(const auto & d : m_directions) {
            int dx = x + d.first;
            int dy = y + d.second;
            
            if( dx < 0 || dy < 0 || dx >= matrix.size() || dy >= matrix[0].size())
                continue;
            if( matrix[dx][dy] < matrix[x][y]) continue;            
                       
            dfs(matrix,visited,dx,dy);            
        }
    }
};