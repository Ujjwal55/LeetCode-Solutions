class Solution {
public:
    int maxAmount(vector<int> &nums, int i, vector<int> &dp){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + maxAmount(nums, i-2, dp), maxAmount(nums, i-1, dp));
    }
    int bottomUp(vector<int> &nums, int n, vector<int> &dp){
        dp[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(i > 1) dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            else{
                dp[i] = max(nums[i], dp[i-1]);
            }
        }
        return dp[n-1];
    }
    int bottomUpOptimised(vector<int> &nums, int n, vector<int> &dp){
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1 ; i < n ; i++){
            int opt1 = nums[i];
            if(i > 1) opt1 += prev2;
            int opt2 = prev;
            int curr = max(opt1, opt2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        // return maxAmount(nums, n-1, dp);
        // return bottomUp(nums, n, dp);
        return bottomUpOptimised(nums, n, dp);
    }
};