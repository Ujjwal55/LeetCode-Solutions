class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m ;
        vector<int> result;
        for(int i = 0 ; i < nums.size(); i++){
            int number = target - nums[i]; 
            auto it = m.find(number);
            if(it != m.end()){
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};