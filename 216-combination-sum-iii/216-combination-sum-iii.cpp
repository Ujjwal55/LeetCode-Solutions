class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int idx){
        if(temp.size() == k){
            int sum = 0;
            for(int i = 0 ; i < temp.size() ; i++){
                sum += temp[i];
            }
            if(sum == n) ans.push_back(temp);
            return;
        }
        if(idx > 9) return;
        temp.push_back(idx);
        combination(ans, temp, k, n, idx+1);
        temp.pop_back();
        combination(ans, temp, k, n, idx+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans, temp, k, n, 1);
        return ans;
    }
};