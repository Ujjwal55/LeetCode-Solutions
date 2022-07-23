class Solution {
public:
     class cmp{
        bool operator()(pair<int, vector<int>> &p1, pair<int, vector<int>> &p2){
            return p1.first > p2.first;
        }
     };
    int kthSmallest(vector<vector<int>>& mat, int k) {
        // priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp>pq;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        set<vector<int>> s;
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        vector<int> temp;
        for(int i = 0 ; i < n ; i++){
            sum += mat[i][0];
            temp.push_back(0);
        }
        s.insert(temp);
        pq.push({sum, temp});
        
        while(k--){
            sum = pq.top().first;
            temp = pq.top().second;
            pq.pop();
            if(!k) return sum;
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i] + 1 < m){
                    int curr = sum - mat[i][temp[i]] + mat[i][temp[i] + 1];
                    temp[i]++;
                    if(!s.count(temp)){
                        s.insert(temp);
                        pq.push({curr, temp});
                    }
                    temp[i]--;
                }
            }
        }
        return 0;
    }
};