class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ')'){
                if(!stk.size()){
                    stk.push_back(i);
                    continue;
                }
                bool removed = false;
                while(stk.size() && s[i] == ')' && s[stk.back()] == '('){
                    stk.pop_back();
                    removed = true;
                    break;
                }

                if(!removed){
                    stk.push_back(i);
                }
            }
        }
        
       while(stk.size()){
        s[stk.back()] = '@';
        stk.pop_back();
       }


       string ans = "";
       for(auto it : s){
        if(it != '@'){
            ans += it;
        }
       }

       return ans;
    }
};