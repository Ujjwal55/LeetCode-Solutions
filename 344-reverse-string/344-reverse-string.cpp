class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size() - 1;
        // cout<<n;
        for(int i = 0 ; i <= n/2 ; i++){
            char temp = s[i];
            s[i] = s[n-i];
            s[n-i] = temp;
        }
    }
};