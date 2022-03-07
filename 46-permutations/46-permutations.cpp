class Solution {
public:
    void permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n ; i++){
            if(find(temp.begin(), temp.end(), nums[i]) == temp.end()){
                temp.push_back(nums[i]);
                permutation(nums, ans, temp, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        permutation(nums, ans, temp, n);
        return ans;
    }
};