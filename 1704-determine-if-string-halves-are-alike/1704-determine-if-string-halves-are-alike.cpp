class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 1 ; i <= n ; i++){
            if(i <= n/2){
                if(s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u') cnt1++;
            }
            else{
                if(s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u') cnt2++;
            }
        }
        return cnt1 == cnt2;
    }
};