class Solution {
public:
    int lis(vector<int> &nums, int i, vector<int> &dp){
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = 0 ; j < i ; j++){
            if(nums[j] < nums[i]){
                ans = max(ans, lis(nums, j, dp) + 1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), -1);
        for(int i = 0 ; i < nums.size() ; i++){
            ans = max(ans, lis(nums, i, dp));
        }
        return ans;
    }
};