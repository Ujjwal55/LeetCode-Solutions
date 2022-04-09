class Solution {
public:
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = 0;
    //     int len = INT_MAX;
    //     for(int i = 0 ; i < n ; i++){
    //         int sum = 0;
    //         for(int j = i ; j < n ; j++){
    //             sum += nums[j];
    //             if(sum >= target){
    //                 len = min(len, j - i + 1);
    //                 break;
    //             }
    //         }
    //     }
    //     return len != INT_MAX ? len : 0;
    // }
    
    bool subarraySum(vector<int> &nums, int target, int n, int k){
        
        int sum = 0;
        for(int i = 0 ; i < k ; i ++) sum += nums[i];
        int maxi = sum;
        int l = 0 , r = k;
        while(r <= n-1){
            sum -= nums[l];
            l++;
            
            sum += nums[r];
            r++;
            
            maxi = max(sum, maxi);
        }
        return maxi >= target;
    }
    int minSubArrayLen(int target, vector<int> &nums){
        int n = nums.size();
        int low = 1 , high = n;
        bool check = false;
        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(subarraySum(nums, target, n, mid) == true){
                check = true;
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        if(check) return low;
        if(low == n){
            int sum = 0;
            for(int i = 0 ; i < n ; i++) sum += nums[i];
            if(sum >= target) return low;
        }
        return 0;
    }
};