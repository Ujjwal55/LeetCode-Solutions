// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void printPaths(vector<vector<int>> &maze, vector<string> &ans, vector<vector<int>> &visited, string path, int n, int i, int j){
        if(i > n-1 || i < 0 || j > n-1 || j < 0) return;
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        if(visited[i][j] == 1 || maze[i][j] == 0) return;
        visited[i][j] = 1;
        printPaths(maze, ans, visited, path+'D', n, i+1, j);
        printPaths(maze, ans, visited, path+'L', n, i, j-1);
        printPaths(maze, ans, visited, path+'R', n, i, j+1);
        printPaths(maze, ans, visited, path+'U', n, i-1, j);
        visited[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
        printPaths(m, ans, visited, "", n, 0, 0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends