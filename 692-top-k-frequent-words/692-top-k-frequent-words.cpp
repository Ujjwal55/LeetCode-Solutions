class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string> p1, pair<int, string> p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> m;
        vector<string> ans;
        for(auto it : words){
            m[it]++;
        }
        for(auto it : m){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};