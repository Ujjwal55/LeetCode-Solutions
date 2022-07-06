class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto it : nums){
            m[it]++;
        }
        
        for(auto it : m){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};