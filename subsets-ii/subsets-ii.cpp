class Solution {
public:
    void printSubsets(vector<int> &nums,vector<int> &v,vector<vector<int>> &ans,int n,int i){
        if(i == n){
            vector<int> t;
            for(auto it: v){
                t.push_back(it);
            }
            sort(t.begin(), t.end());
            auto it = find(ans.begin(), ans.end(), t);
            if(it == ans.end()){
            ans.push_back(t);
            }
            return;
        }
        v.push_back(nums[i]);
        printSubsets(nums, v, ans, n, i+1);
        v.pop_back();
        printSubsets(nums, v, ans, n, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<vector<int>> ans;
        printSubsets(nums, v, ans, n, 0);
        return ans;
    }
};