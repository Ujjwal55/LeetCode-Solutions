class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        if(n % 2 != 0) return false;
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++){
            int rem = ((arr[i]%k)+k)%k;
            m[rem]++;
        }
        for(auto it : m){
            int first = it.first;
            int second = k - it.first;
            if(first == 0){
                if(it.second % 2 != 0) return false;
            }
            else if(m[first] != m[second]) return false;
        }
        return true;
    }
};