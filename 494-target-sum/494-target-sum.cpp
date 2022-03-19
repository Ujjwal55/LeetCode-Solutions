class Solution {
public:
    int noOfWays(vector<int> &nums, int target, int total, int n, unordered_map<string, int> &dp){
        if(n == 0){
            if(target == 0) return 1;
            return 0;
        }
        string key = to_string(n) + " " + to_string(target);
        if(dp.find(key) != dp.end()) return dp[key];
        return dp[key] = noOfWays(nums, target-nums[n-1], total, n-1, dp) + noOfWays(nums, target+nums[n-1], total, n-1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i = 0 ; i < n ; i++) total+=nums[i];
        // vector<vector<int>> dp(n+1, vector<int> (total+1, -1));
        unordered_map<string, int> dp;
        return noOfWays(nums, target, total, n, dp);
    }
};