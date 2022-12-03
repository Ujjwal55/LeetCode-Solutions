class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for(auto it : s){
            m[it]++;
        }
        string ans="";
        for(auto it : m){
            pq.push({it.second, it.first});
        }
        while(pq.size()){
            int k = pq.top().first;
            char c = pq.top().second;
            while(k--){
                ans += c;
            }
            pq.pop();
        }
        return ans;
    }
};