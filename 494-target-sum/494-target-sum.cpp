class Solution {
public:
    int noOfWays(vector<int> &nums, int target, int n, unordered_map<string, int> &dp){
        if(n == 0){
            if(target == 0) return 1;
            return 0;
        }
        string key = to_string(n) + " " + to_string(target);
        if(dp.find(key) != dp.end()) return dp[key];
        return dp[key] = noOfWays(nums, target-nums[n-1], n-1, dp) + noOfWays(nums, target+nums[n-1], n-1, dp);
    }
    int bottomUp(vector<int> &nums, int target, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= sum ; j++){
               if(i == 0) dp[i][j] = 0;
               if(j == 0) dp[i][j] = 1; 
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= sum ; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int> (total+1, -1));
        unordered_map<string, int> dp;
        // return noOfWays(nums, target, n, dp);
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += nums[i];
        if(sum < target || (sum+target)%2 != 0) return 0;
        return bottomUp(nums, target, (sum+target)/2);
    }
};