class Solution {
public:
    void fill(vector<vector<int>> &image, int sr, int sc, int newColor, int toCheck, int m, int n){
        if(sr < 0 || sc < 0 || sr > m-1 || sc > n-1) return;
        if(image[sr][sc] != toCheck) return;
        image[sr][sc] = newColor;
        fill(image, sr, sc+1, newColor, toCheck, m, n);
        fill(image, sr+1, sc, newColor, toCheck, m, n);
        fill(image, sr, sc-1, newColor, toCheck, m, n);
        fill(image, sr-1, sc, newColor, toCheck, m, n);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int toCheck = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        fill(image, sr, sc, newColor, toCheck, m, n);
        return image;
    }
};