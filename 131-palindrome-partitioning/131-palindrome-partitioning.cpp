class Solution {
public:
    void printPalindrome(vector<vector<string>> &ans, string s, vector<string> &temp, int i){
        if(i == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int j = i ; j < s.length() ; j++){
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j - i + 1));
                printPalindrome(ans, s, temp, j+1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        printPalindrome(ans, s, temp, 0);
        return ans;
    }
};