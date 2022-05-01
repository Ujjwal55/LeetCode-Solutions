class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // int m = s.size();
        // int n = t.size();
        // for(auto it: s){
        //     if(it == '#'){
        //         auto idx = distance(s.begin(), it);
        //         s.erase(idx - 1, idx);
        //     }
        // }
        // // {
        // //     if(t[i] == '#'){
        // //         t.erase(t.begin()+i-1, t.begin()+i);
        // //     }
        // // }
        // // if(s == t) return true;
        // // else return false;
        // cout<<s;
        // return false;
        
        stack<char> st1;
        stack<char> st2;
        for(auto it : s){
            if(it == '#'){
                if(!st1.empty()) st1.pop();
            }
            else st1.push(it);
        }
        
        for(auto it : t){
            if(it == '#'){
                if(!st2.empty()) st2.pop();
            }
            else st2.push(it);
        }
        return st1 == st2;
    }
};