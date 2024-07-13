class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<int> index(n);
        
        for(int i = 0 ; i < n ; i++) {
            index[i] = i;
        }
        
        sort(index.begin(), index.end(), [&](auto &i, auto &j) {
            if(positions[i] < positions[j]) {
                return true;
            }
            return false;
        });
        
        vector<int> ans;
        
        stack<int> st;
        
        
        for(auto &it: index) {
            if(directions[it] == 'R') {
                st.push(it);
            } else {
                while(!st.empty() && healths[it] > 0) {
                    int top = st.top();
                    st.pop();
                    
                    if(healths[top] > healths[it]) {
                        healths[top] -= 1;
                        healths[it] = 0;
                        st.push(top);
                    } else if(healths[top] < healths[it]) {
                        healths[it] -= 1;
                        healths[top] = 0;
                    } else {
                        healths[top] = 0;
                        healths[it] = 0;
                    }
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        
        return ans;
    }
};