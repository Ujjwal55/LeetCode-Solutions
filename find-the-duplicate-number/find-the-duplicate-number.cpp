class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t ans = 0;
        for(size_t i = 0;i<nums.size()-1;i++){
            if((nums.at(i) - nums.at(i+1)) == 0){
                ans = nums.at(i);
                break;
            }
        }
        return ans;
        
    }
};