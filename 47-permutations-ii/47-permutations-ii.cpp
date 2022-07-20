class Solution {
public:
    void permutation(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<bool> &visited, int n){
        if(temp.size() == n){
            vector<int> t = temp;
            if(find(ans.begin(), ans.end(), t) == ans.end()){
                ans.push_back(temp);
            }
            return;
        }
        for(int idx = 0 ; idx < n ; idx++){
            if(!visited[idx]){
                visited[idx] = true;
                temp.push_back(nums[idx]);
                permutation(ans, temp, nums, visited, n);
                visited[idx] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> visited(n, false);
        permutation(ans, temp, nums, visited, n);
        return ans;
    }
};