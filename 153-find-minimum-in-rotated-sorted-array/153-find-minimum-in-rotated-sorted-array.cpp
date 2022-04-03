class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        // while(low < high){
        //     int mid = low + (high - low) / 2;
        //     if(nums[mid] < nums[high]){
        //         high = mid;
        //     }
        //     else{
        //         low = mid + 1;
        //     }
        // }
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[low] < nums[high]) return nums[low];
            if(nums[mid] >= nums[low]){
                ans = nums[low];
                low = mid + 1;
            }
            // else if(nums[mid] == nums[low]){
            //     ans = min(nums[low], nums[high]);
            //     high = mid - 1;
            // }
            else{
                high = mid;
            }
        }
        return min(ans, nums[low]);
    }
};