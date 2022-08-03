class Solution {
public:
    int maxSubset(vector<string> &strs, int sz, int zeros, int ones, vector<vector<vector<int>>> &numberofSubsets){
        if(zeros < 0 || ones < 0) return INT_MIN;
        if(sz == 0) return 0;
        if(zeros == 0 && ones == 0) return 0;
        if(numberofSubsets[sz][zeros][ones] != -1) return numberofSubsets[sz][zeros][ones];
        string subset = strs[sz-1];
        int zero = 0, one = 0;
        for(int i = 0 ; i < subset.size() ; i++){
            if(subset[i] == '0') zero++;
            else one++;
        }
        return numberofSubsets[sz][zeros][ones] =  max(1 + maxSubset(strs, sz-1, zeros-zero, ones-one, numberofSubsets), maxSubset(strs, sz-1, zeros, ones, numberofSubsets));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> numberofSubsets(sz+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return maxSubset(strs, sz, m, n, numberofSubsets);
    }
};