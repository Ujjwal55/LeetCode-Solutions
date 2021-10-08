class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int min = i;
            for(int j=i;j<nums.size();j++){
                if(nums[min] > nums[j]){
                    min = j;
                }
            }
            swap(nums[min],nums[i]);
        }
    }
};