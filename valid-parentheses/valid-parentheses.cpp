class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        for(int i = 0 ; i < size ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            if(s[i] == ']'){
                if(st.empty()){
                    return false;
                }
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            if(s[i] == '}'){
                if(st.empty()){
                    return false;
                }
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};