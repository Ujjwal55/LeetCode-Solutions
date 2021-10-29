class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 0){
            vector<vector<int>> ans;
            return ans;
        }
        sort(nums.begin() ,nums.end());
        set<vector<int>> s;
        for(int i = 0 ; i< nums.size()-1; i++){
            int lo = i+1;
            int hi = nums.size()-1;
            int target = 0 - nums[i];
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    s.insert({nums[i],nums[lo], nums[hi]});
                    while(lo < hi && nums[lo] == nums[lo+1])
                        lo++;
                    while(lo < hi && nums[hi] == nums[hi-1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo] + nums[hi] < target)
                    lo++;
                else
                    hi--;
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};