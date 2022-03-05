class Solution {
public:
    void combination(string digits, int i, string temp, vector<string> &ans, map<char,string> &m){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int digit = i ; digit < digits.size() ; digit++){
            char c = digits[digit];
            for(int alphabet = 0 ; alphabet < m[c].size() ; alphabet++){
                char ch = m[c][alphabet];
                temp.push_back(ch);
                combination(digits, digit+1, temp, ans, m);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        if(digits.size() == 0) return {};
        combination(digits, 0, "", ans, m);
        return ans;
    }
};