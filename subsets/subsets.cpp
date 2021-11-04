class Solution {
public:
    void printSubsets(vector<int> &nums, vector<int> &s, vector<vector<int>> &v, int n, int i){
        if(i==n){
             vector<int> t;
            for(auto it: s){
                t.push_back(it);
            }
            v.push_back(t);
            return;
        }
        s.push_back(nums[i]);
        printSubsets(nums, s, v, n, i+1);
        s.pop_back();
        printSubsets(nums, s, v, n, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        vector<int> s;
        printSubsets(nums, s, v, n, 0);
        return v;
    }
};