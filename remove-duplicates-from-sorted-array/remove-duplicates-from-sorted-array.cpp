class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int lo=0,hi=lo+1;
        while(hi<nums.size()){
            if(nums[lo] == nums[hi]) hi++;
            else{
                lo++;
                nums[lo]=nums[hi];
                hi++;
            }
        }
        return lo+1;
    }
};