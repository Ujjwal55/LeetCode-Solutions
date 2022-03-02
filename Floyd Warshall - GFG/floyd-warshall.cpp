// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int V = matrix.size();
	    int costs[V][V];
	    
	    for(int i = 0 ; i < V ; i++){
	        for(int j = 0 ; j < V ; j++){
	            costs[i][j] = matrix[i][j];
	        }
	    }
	    
	    for(int i = 0 ; i < V ; i++){
	        for(int j = 0 ; j < V ; j++){
	            for(int k = 0 ; k < V ; k++){
	                if(costs[j][i] == -1 || costs[i][k] == -1) continue;
	                if(costs[j][k] == -1) costs[j][k] = costs[j][i] + costs[i][k];
	                else costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
	            }
	        }
	    }
	    
	    for(int i = 0 ; i < V ; i++){
	        for(int j = 0 ; j < V ; j++){
	            matrix[i][j] = costs[i][j];
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends