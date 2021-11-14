class Solution {
public:
    void printSubsets(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans, int target, int n, int i){
        if(i == n){
            if(target == 0){
                vector<int> t;
                for(auto it: v){
                    t.push_back(it);
                }
                ans.push_back(t);
            }
            return;
        }
        if(nums[i] <= target){
            v.push_back(nums[i]);
            printSubsets(nums, v, ans, target-nums[i], n, i);
            v.pop_back();
        }
        printSubsets(nums, v, ans, target, n, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> v;
        vector<vector<int>> ans;
        printSubsets(candidates, v, ans, target, n, 0);
        return ans;
    }
};