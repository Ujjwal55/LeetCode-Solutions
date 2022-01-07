// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void printPath(vector<vector<int>> &nums, vector<vector<int>> &visited, 
    vector<string> &ans, string move, int n, int i, int j){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        //downward
        if(i+1 <n && !visited[i+1][j] && nums[i+1][j]){
            visited[i][j] = 1;
            printPath(nums, visited, ans, move+'D', n, i+1, j);
            visited[i][j] = 0;
        }
        //leftwards
        if(j-1 >= 0 && !visited[i][j-1] && nums[i][j-1]){
            visited[i][j] = 1;
            printPath(nums, visited, ans, move+'L', n, i, j-1);
            visited[i][j] = 0;
        }
        //rightwards
        if(j+1 < n && !visited[i][j+1] && nums[i][j+1]){
            visited[i][j] = 1;
            printPath(nums, visited, ans, move+'R', n, i, j+1);
            visited[i][j] = 0;
        }
        //upwards
        if(i-1 >= 0 && !visited[i-1][j] && nums[i-1][j]){
            visited[i][j] = 1;
            printPath(nums, visited, ans, move+'U', n, i-1, j);
            visited[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int> (n, 0));
        if(m[0][0] == 1){
            printPath(m, visited, ans, "", n, 0, 0);
        }
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