class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        int a=1;
        // sort(nums.begin(), nums.end());
        for(size_t i=0;i<nums.size();i++){
            // sum+=nums[i];
            v[0] = i;
            for(size_t j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target){
                    v[1] = j;
                    a=0;
                    break;
                }
            }
            if(a==0)
                break;
            
        }
        return v;
    }
};