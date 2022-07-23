class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0 ; i < min(n, k) ; i++){
            pq.push({matrix[i][0], i, 0});
        }
        int ans = 0;
        for(int i = 1 ; i <= k ; i++){
            ans = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(y + 1 < n){
                pq.push({matrix[x][y+1], x, y+1});
            }
        }
        return ans;
    }
};