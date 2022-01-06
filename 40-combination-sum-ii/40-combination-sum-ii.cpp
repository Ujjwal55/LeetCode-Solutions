class Solution {
public:
    void printCombination(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int target, int previous, int n, int i){
        if(target == 0 || n == i){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        for(int j = i ; j < n ; j++){
            if(j > i && nums[j] == nums[j-1] ) continue;
            if(nums[j] > target) break;
            temp.push_back(nums[j]);
            // previous = nums[j];
            printCombination(ans, nums, temp, target-nums[j], previous, n, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        printCombination(ans, candidates, temp, target, 0, n, 0);
        return ans;
    }
};