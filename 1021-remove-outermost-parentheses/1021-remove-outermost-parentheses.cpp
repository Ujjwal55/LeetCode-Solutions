class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        
        string ans;
        int count = 0;
        
        for(int i = 0 ; i < n ; i++) {
            if(count == 0) {
                count++;
                continue;
            }
            if(s[i] == '(') {
                count++;
            } else {
                count--;
            }
            if(count != 0) {
                ans += s[i];
            }
        }
        
        return ans;
    }
};