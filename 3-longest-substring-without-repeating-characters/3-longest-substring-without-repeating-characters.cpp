class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int right = 0 , left = 0, len = 0;
        for( ; right < s.length() ; right++){
            int currchar = s[right];
            if(m.find(currchar) != m.end() && m[currchar] >= left){
                left = m[currchar] + 1;
            }
            m[currchar] = right;
            int temp_len = right - left + 1;
            len = max(len, temp_len);
        }
        return len;
    }
};