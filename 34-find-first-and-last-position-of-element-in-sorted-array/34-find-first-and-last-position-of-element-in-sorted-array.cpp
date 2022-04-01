class Solution {
public:
    int firstPosition(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int lastPosition(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target){
                return {0, 0};
            }
        }
        vector<int> ans(2);
        ans[0] = firstPosition(nums, target);
        ans[1] = lastPosition(nums, target);
        return ans;
    }
};