class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> odd;
        vector<int> even;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] & 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        for(auto it : even){
            ans.push_back(it);
        }
        for(auto it: odd){
            ans.push_back(it);
        }
        return ans;
    }
};