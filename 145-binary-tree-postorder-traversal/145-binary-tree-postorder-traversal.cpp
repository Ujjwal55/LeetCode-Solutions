/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode *> st;
        unordered_map<TreeNode *, bool> visited;
        st.push(root);
        TreeNode *front=st.top();
        while(!st.empty()){
            TreeNode *temp = st.top();
            while((temp->left and !visited[temp->left]) || (temp->right and !visited[temp->right])){
                while(temp->left && !visited[temp->left]){
                    st.push(temp->left);
                    temp=temp->left;
                }
                if(temp->right && !visited[temp->right]){
                    temp=temp->right;
                    st.push(temp);
                }
            }
            temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            visited[temp] = true;
        }
        return ans;
    }
};