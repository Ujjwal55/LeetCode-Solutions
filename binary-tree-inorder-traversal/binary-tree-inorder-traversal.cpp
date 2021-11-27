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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode *> st;
        TreeNode *temp;
        st.push(root);
        temp = st.top();
        while(!st.empty()){
            while(temp->left){
                st.push(temp->left);
                if(temp->left)
                    temp=temp->left;
            }
            TreeNode *front = st.top();
            ans.push_back(front->val);
            st.pop();
            if(front->right){
                temp=front->right;
                st.push(temp);
                 while(temp->left){
                     st.push(temp->left);
                     if(temp->left)
                         temp=temp->left;
                 }
            }
        }
        return ans;
    }
};