class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        for(int i = 0 ; i < n ; i++){
            m[s[i]]++;
        }
        string ans = "";
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