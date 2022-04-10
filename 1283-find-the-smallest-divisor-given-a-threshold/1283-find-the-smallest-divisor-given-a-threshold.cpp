class Solution {
public:
    bool sum(vector<int> &nums, int threshold, int n, int mid){
        
        int s = 0;
        for(int i = 0 ; i < n ; i++){
            // s += nums[i]/mid;
            // if(nums[i] % mid != 0) s += 1;
            s += ceil(float(nums[i]) / float(mid));
        }
        return s <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        
        int low = 1, high = maxi;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(sum(nums, threshold, n, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};