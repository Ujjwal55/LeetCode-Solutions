class Solution {
public:
    void combination(vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target, int n, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx ; i < n ; i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            combination(candidates, temp, ans, target-candidates[i], n, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        combination(candidates, temp, ans, target, n, 0);
        return ans;
    }
};