class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i, int n, int target){
        if(target < 0) return;
        if(i == n || target == 0){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[i]);
        combination(ans, temp, nums, i, n, target-nums[i]);
        temp.pop_back();
        combination(ans, temp, nums, i+1, n, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        combination(ans, temp, nums, 0, n, target);
        return ans;
    }
};