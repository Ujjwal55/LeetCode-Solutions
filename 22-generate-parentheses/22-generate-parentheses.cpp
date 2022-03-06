class Solution {
public:
    void parenthesis(vector<string> &ans, int open, int close, int n, string temp){
        if(temp.size() == 2*n){
            ans.push_back(temp);
        }
        if(open < n){
            temp.push_back('(');
            parenthesis(ans, open+1, close, n, temp);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            parenthesis(ans, open, close+1, n, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        parenthesis(ans, 0, 0, n, temp);
        return ans;
    }
};