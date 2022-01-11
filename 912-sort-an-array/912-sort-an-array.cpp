class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
        // int max = *max_element(nums.begin(), nums.end());
        // int n = nums.size();
        // vector<int> count(max+1, 0);
        // vector<int> output;
        // for(int i = 0 ; i < n ; i++){
        //     count[nums[i]]++;
        // }
        // for(int i = 1 ; i < n ; i++){
        //     count[i] += count[i-1]; 
        // }
        // for(int i = 0 ; i < n ; i++){
        //     output[count[nums[i]] - 1] = nums[i];
        //     --count[nums[i]];
        // }
        // return output;
    }
};