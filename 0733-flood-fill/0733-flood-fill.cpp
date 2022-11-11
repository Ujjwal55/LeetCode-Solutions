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

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startingColor = image[sr][sc];
        if(startingColor == color) return image;
        fill(image, sr, sc, startingColor, color, m, n);
        return image;
    }
};