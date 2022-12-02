class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1, s2;
        vector<int> v1(26), v2(26);
        for(auto it : word1){
            v1[it-'a']++;
            s1.insert(it);
        }
        for(auto it : word2){
            v2[it - 'a']++;
            s2.insert(it);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return s1 == s2 && v1 == v2;
    }
};