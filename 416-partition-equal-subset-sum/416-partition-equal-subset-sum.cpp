class Solution {
public:
    bool partition(vector<int> &nums, int i, int sum, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(sum < 0 || i < 0) return false;
        if(i == 0){
            if(sum-nums[i] == 0) return true;
            return false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        if(nums[i] <= sum){
            return dp[i][sum] = partition(nums,i-1,sum-nums[i],dp) || partition(nums,i-1,sum,dp);
        }
        return dp[i][sum] = partition(nums, i-1, sum, dp);
    }
    bool bottomUp(vector<int> &nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= sum ; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        // for(int i = 0 ; i < n ; i++) dp[i][0] = true;
        // dp[0][nums[0]] = true;
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= sum ; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += nums[i];
        vector<vector<int>> dp(n, vector<int> (sum/2+1, -1));
        if(sum%2 != 0) return false;
        // return partition(nums, n-1, sum/2, dp);
        return bottomUp(nums, sum/2);
    }
};