class Solution {
public:
    int minimumSwaps(vector<int>& nums1, vector<int>& nums2, int prevA, int prevB, int swap, int i, vector<vector<int>> &dp){
        if(i == nums1.size()){
            return 0;
        }
        if(dp[i][swap] != -1) return dp[i][swap];
        int minSwaps = INT_MAX;
        if(nums1[i] > prevA && nums2[i] > prevB){
            minSwaps = minimumSwaps(nums1, nums2, nums1[i], nums2[i], 0, i+1, dp);
        }
        if(nums2[i] > prevA && nums1[i] > prevB){
            minSwaps = min(minSwaps, minimumSwaps(nums1, nums2, nums2[i], nums1[i], 1, i+1, dp) + 1);
        }
        return dp[i][swap] = minSwaps;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (2, -1));
        return minimumSwaps(nums1, nums2, -1, -1, 0, 0, dp);
    }
};