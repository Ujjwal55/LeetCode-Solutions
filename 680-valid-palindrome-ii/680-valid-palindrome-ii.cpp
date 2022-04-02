class Solution {
public:
    bool checkPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int low = 0, high = n-1;
        while(low < high){
            if(s[low] != s[high]){
                return checkPalindrome(s, low+1, high) || checkPalindrome(s, low, high-1);
            }
            low++, high--;
        }
        return true;
    }
};