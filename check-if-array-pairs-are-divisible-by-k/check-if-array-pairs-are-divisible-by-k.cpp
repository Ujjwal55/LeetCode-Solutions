class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto it: arr){
            m[((it%k)+k)%k]++;
        }
        if(m[0]&1)
            return false;
        for(int i = 1 ; i < k ; i++){
            if(m[i] != m[k-i])
                return false;
        }
        return true;
    }
};