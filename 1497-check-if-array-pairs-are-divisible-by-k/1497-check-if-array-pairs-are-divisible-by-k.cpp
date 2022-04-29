class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++){
            m[((arr[i]%k)+k)%k]++;
        }
        
        for(auto it: m){
            int f = it.first;
            int sec = k - it.first;
            if(f == 0){
                if(it.second & 1) return false;
            }
            else if(m[f] != m[sec]) return false;
        }
        return true;
    }
};