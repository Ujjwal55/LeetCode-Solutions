class Solution {
public:
    void rec(vector<string> &ans, string temp, int start, int end, int n){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
        }
        if(start < n){
            temp.push_back('(');
            rec(ans, temp, start+1, end, n);
            temp.pop_back();
        }
        if(end < start){
            temp.push_back(')');
            rec(ans, temp, start, end + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        
        rec(ans, temp, 0, 0, n);
        return ans;
    }
};