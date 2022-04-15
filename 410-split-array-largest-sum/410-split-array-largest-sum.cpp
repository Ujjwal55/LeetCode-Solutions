class Solution {
public:
    bool numberOfSubarrays(vector<int> &nums, int n, int mid, int m){
        int cnt = 1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > mid) return false;
            sum += nums[i];
            if(sum > mid){
                cnt++;
                sum = nums[i];
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        
        int high = 0;
        for(int i = 0 ; i < n ; i++) high += nums[i];
        
        int low = mini, ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(numberOfSubarrays(nums, n, mid, m) == false){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};