class Solution {
public:
    unordered_map<char, string> m;
    void phoneNumber(vector<string> &ans, string s, string digits, int i){
        if(s.size() == digits.size()){
            ans.push_back(s);
            return;
        }
        for(int digit = i ; digit < digits.size() ; digit++){
            char c = digits[digit];
            for(int alphabet = 0 ; alphabet < m[c].size() ; alphabet++){
                s.push_back(m[c][alphabet]);
                phoneNumber(ans, s, digits, digit+1);
                s.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        if(digits.size()== 0) return {};
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        phoneNumber(ans, "", digits, 0);
        return ans;
    }
};