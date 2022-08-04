class Solution {
public:
    int findSubset(vector<int> &nums, int sz, int target, vector<vector<int>> &subsets){
        if(target == 0) return 1;
        if(target < 0 || sz == 0) return 0;
        if(subsets[sz][target] != -1) return subsets[sz][target];
        if(nums[sz-1] <= target){
            return subsets[sz][target] = findSubset(nums, sz-1, target-nums[sz-1], subsets) + findSubset(nums, sz-1, target, subsets);
        }
        else return subsets[sz][target] = findSubset(nums, sz-1, target, subsets);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, zero = 0;
        vector<int> arr;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(nums[i] == 0) zero++;
            else arr.push_back(nums[i]);
        }
        int sz = n - zero;
        int new_target = (sum + target) / 2;
        if((sum + target) % 2 != 0 || new_target < 0) return 0;
        vector<vector<int>> subsets(sz+1, vector<int> (new_target+1, -1));
        
        return pow(2, zero) * findSubset(arr, sz, new_target, subsets);
    }
};