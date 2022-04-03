class Solution {
public:
    // bool checkSorted(vector<int> &nums, int start, int end){
    //     while(start < end){
    //         if(nums[start] > nums[end]) return false;
    //     }
    //     return true;
    // }
    // void nextPermutation(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i = 0 ; i < n-1 ; i++){
    //         if(checkSorted(nums, i+1, n-1))
    //     }
    // }
    void nextPermutation(vector<int> &nums){
        int n = nums.size();
        int idx = n - 2;
        while(idx >= 0 && nums[idx+1] <= nums[idx]){
            idx--;        
        }
        if(idx >= 0){
            int largerIdx = n - 1;
            while(nums[largerIdx] <= nums[idx]){
                largerIdx--;
            }
            swap(nums[idx], nums[largerIdx]);
        }
        reverse(nums.begin() + idx + 1 , nums.end());
    }
};