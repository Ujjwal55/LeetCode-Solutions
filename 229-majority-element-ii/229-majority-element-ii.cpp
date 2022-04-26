class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         int cnt = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             cnt = 0;
//             for(int j = i ; j < n ; j++){
//                 if(nums[j] == nums[i]) cnt++;
//             }
//             if(cnt > n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end()) ans.push_back(nums[i]);
//         }
//         return ans;
        
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++) m[nums[i]]++;
        for(auto it: m){
            if(it.second > n/3) ans.push_back(it.first);
        }
        return ans;
    }
};