class Solution {
public:
    void permutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited, int n){
        if(temp.size() == n){
            vector<int> t = temp;
            if(find(ans.begin(), ans.end(), t) == ans.end()) ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                permutations(nums, ans, temp, visited, n);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        vector<int> temp;
        permutations(nums, ans, temp, visited, n);
        return ans;
    }
};