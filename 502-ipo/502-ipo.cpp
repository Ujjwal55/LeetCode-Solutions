class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> p;
        multiset<pair<int, int>> c;
        int  n = profits.size();
        
        for(int i = 0 ; i < n ; i++){
            if(capital[i] <= w){
                p.push(profits[i]);
            }
            else{
                c.insert({capital[i], profits[i]});
            }
        }
        while(k-- && !p.empty()){
            w += p.top();
            p.pop();
            
            for(auto &val : c){
                if(val.first <= w){
                    p.push(val.second);
                    c.erase(c.lower_bound(val));
                }
            }
        }
        return w;
    }
};