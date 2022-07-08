class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for(auto it : s){
            m[it]++;
        }
        for(auto it : m){
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(pq.size() > 1){
            char firstc = pq.top().second;
            int firsti = pq.top().first;
            pq.pop();
            char secondc = pq.top().second;
            int secondi = pq.top().first;
            pq.pop();
            ans += firstc;
            ans += secondc;
            firsti--;
            secondi--;
            if(firsti > 0) pq.push({firsti, firstc});
            if(secondi > 0) pq.push({secondi, secondc});
        }
        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};