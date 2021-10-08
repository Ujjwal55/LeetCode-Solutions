class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                v.push_back(nums[i]);
                // nums.erase(nums.begin()+i);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                v.push_back(nums[i]);
                // nums.erase(nums.begin()+i);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 2){
                v.push_back(nums[i]);
            }
        }
        for(int i=0;i<v.size();i++){
            nums[i] = v[i];
        }
    }
};