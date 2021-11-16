class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int lo = 0, hi = n-1;
        for(int i = n-1 ; i >= 0 ; i--){
            if(abs(nums[lo]) < abs(nums[hi])){
                ans[i] = nums[hi]*nums[hi];
                hi--;
            }
            else{
                ans[i] = nums[lo]*nums[lo];
                lo++;
            }
        }
        return ans;
    }
};