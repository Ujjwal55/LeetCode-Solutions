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
        
        // vector<int> ans;
        // int n = nums.size();
        // unordered_map<int, int> m;
        // for(int i = 0 ; i < n ; i++) m[nums[i]]++;
        // for(auto it: m){
        //     if(it.second > n/3) ans.push_back(it.first);
        // }
        // return ans;
        
        int n = nums.size();
        vector<int> ans;
        int num1 = INT_MAX, num2 = INT_MAX;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;
            else if(cnt1 == 0){
                num1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                num2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--, cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
        }
        if(cnt1 > n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        return ans;
    }
};