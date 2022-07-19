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
        cout<<"h";
        for(int index = i ; index < n ; index++){
            if(index > i && nums[index] == nums[index-1]) continue;
            temp.push_back(nums[index]);
            combination(ans, temp, nums, index+1, n, target-nums[index]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        combination(ans, temp, nums, 0, n, target);
        return ans;
    }
};