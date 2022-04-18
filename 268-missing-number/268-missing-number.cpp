class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         int n = nums.size();
        
//         int ans = 0;
//         for(int i = 0 ; i < n ; i++){
//             ans = ans ^ nums[i];
//             ans = ans ^ (i+1);
//         }
        
//         return ans;
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for(int i = 0 ; i < n ; i++) sum -= nums[i];
        
        return sum;
    }
};