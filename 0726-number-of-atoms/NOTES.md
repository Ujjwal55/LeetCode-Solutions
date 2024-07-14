class Solution {
public:
string countOfAtoms(string formula) {
stack<int> st;
int n = formula.size();
map<char, int> count;
for(int i = 0 ; i < n ; i++) {
st.push(formula[i]);
}
while(!st.empty()) {
int top = st.top();
st.pop();
if(isdigit(top) && st.top() == ')') {
int top = st.top();
while(!st.empty()) {
int stackTop = st.top();
if(stackTop == '(') {
break;
}
if(count[top]) {
count[top] = count[top] * top;
}
}
}
}
}
};