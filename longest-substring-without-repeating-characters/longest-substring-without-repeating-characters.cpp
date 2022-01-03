class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int a = 0;
            unordered_map<char, int> m;
            for(int j = i ; j < s.length() ; j++){
                if(m.find(s[j]) != m.end()){
                    break;
                }
                m[s[j]] = j;
                a++;
                len = max(len, a);
            }
        }
        return len;
    }
};