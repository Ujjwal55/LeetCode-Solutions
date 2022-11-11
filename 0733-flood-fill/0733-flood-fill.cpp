class Solution {
public:

    void fill(vector<vector<int>>& image, int sr, int sc, int startingColor, int color, int m, int n){
        if(sr < 0 || sr > m-1 || sc < 0 || sc > n-1) return;
        if(image[sr][sc] != startingColor) return;
        image[sr][sc] = color;
        fill(image, sr+1, sc, startingColor, color, m, n);
        fill(image, sr, sc+1, startingColor, color, m, n);
        fill(image, sr-1, sc, startingColor, color, m, n);
        fill(image, sr, sc-1, startingColor, color, m, n);
        return;
    }
    void fillBFS(vector<vector<int>> &image, int sr, int sc, int startingColor, int color, int m, int n){
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int currRow = it.first;
            int currCol = it.second;
            if(currRow < 0 || currRow > m-1 || currCol < 0 || currCol > n-1 || image[currRow][currCol] != startingColor) continue;
            image[currRow][currCol] = color;
            q.push({currRow+1, currCol});
            q.push({currRow, currCol+1});
            q.push({currRow-1, currCol});
            q.push({currRow, currCol-1});  
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startingColor = image[sr][sc];
        if(startingColor == color) return image;
        fillBFS(image, sr, sc, startingColor, color, m, n);
        return image;
    }
};