class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> m;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0){
            vector<vector<int>> ans{};
            return ans;
        }
        for(int i = 0 ; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(int i = 0 ; i< nums.size()-1; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            m[nums[i]]--;
            for(int j = i+1; j < nums.size(); j++){
                m[nums[j]]--;
                int target = nums[i]+nums[j];
                auto it = m.find(-1* target);
                if(it != m.end() && it->second != 0){
                    vector<int> v{nums[i], nums[j], -1*target};
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};