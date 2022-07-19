class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp, int i, int n, int k){
        if(n < 0) return;
        if(i > 9 || n == 0){
            if(n == 0){
                if(temp.size() == k) ans.push_back(temp);
            }
            return;
        }
        for(int index = i ; index <= 9 ; index++){
            temp.push_back(index);
            combination(ans, temp, index+1, n-index, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans, temp, 1, n, k);
        return ans;
    }
};