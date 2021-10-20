class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> v;
        for(int i = 0 ; i< nums.size(); i++){
            if(v.count(nums[i]))
                return nums[i];
            v.insert(nums[i]);
        }
        return -1;
    }
};