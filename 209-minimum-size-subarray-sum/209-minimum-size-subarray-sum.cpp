class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int len = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = i ; j < n ; j++){
                sum += nums[j];
                if(sum >= target){
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }
        return len != INT_MAX ? len : 0;
    }
};