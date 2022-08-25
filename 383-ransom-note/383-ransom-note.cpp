class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(auto it : ransomNote){
            m[it]++;
        }
        for(auto it : magazine){
            if(m.find(it) != m.end()){
                m[it]--;
                if(m[it] == 0) m.erase(it);
            }
        }
        if(m.size() == 0) return true;
        return false;
    }
};