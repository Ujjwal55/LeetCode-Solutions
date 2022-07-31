class Solution {
public:
    bool isSubsetSum(vector<int> &nums, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(sum < 0 || n == 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(nums[n-1] <= sum){
            return dp[n][sum] = isSubsetSum(nums, n-1, sum-nums[n-1], dp) || isSubsetSum(nums, n-1, sum, dp);
        }
        else return dp[n][sum] = isSubsetSum(nums, n-1, sum, dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n+1, vector<int> (sum/2+1, -1));
        return isSubsetSum(nums, n, sum/2, dp);
    }
};