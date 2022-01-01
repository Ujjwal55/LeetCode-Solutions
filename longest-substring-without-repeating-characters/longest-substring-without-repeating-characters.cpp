class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = 0, len = 0, temp_len;
        for(int i = 0 ; i < s.length() ; i++){
            vector<vector<char>> temp;
            temp_len = 0;
            n = 0;
            for(int j = i ; j < s.length() ; j++){
                for(int k = 0 ; k < temp.size() ; k++){
                    if(temp[k][0] == s[j]){
                        n = 1;
                        break;
                    }
                }
                if(n == 1)
                    break;
                temp.push_back({s[j]});
                temp_len++;
            }
            len = max(len, temp_len);
        }
        return len;
    }
};