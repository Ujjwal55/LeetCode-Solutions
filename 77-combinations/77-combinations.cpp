class Solution {
public:
    void printCombination(int n, int k, int start, int p, vector<vector<int>> &ans, vector<int> &temp){
        if(p == k){
            ans.push_back(temp);
            return;
        }
        for(int i = start ; i < n ; i++){
            temp.push_back(i+1);
            printCombination(n, k, i+1, p+1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        printCombination(n, k, 0, 0, ans, temp);
        return ans;
    }
};