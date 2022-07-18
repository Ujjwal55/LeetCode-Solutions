class Solution {
public:
    void rec(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i, int n){
        if(i == n){
            vector<int> t = temp;
            sort(t.begin(), t.end());
            if(find(ans.begin(), ans.end(), t) == ans.end()){
                ans.push_back(t);
            }
            return;
        }
        temp.push_back(nums[i]);
        rec(ans, temp, nums, i+1, n);
        temp.pop_back();
        rec(ans, temp, nums, i+1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        rec(ans, temp, nums, 0, n);
        return ans;
    }
};