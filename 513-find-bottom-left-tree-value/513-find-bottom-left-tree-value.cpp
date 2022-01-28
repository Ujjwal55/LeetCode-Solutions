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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int n = q.size();
            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                TreeNode *top = q.front();
                q.pop();
                if(top->left) {
                    q.push(top->left);
                    if(cnt == 0) ans = top->left->val;
                    cnt++;
                }
                if(top->right) {
                    q.push(top->right);
                    if(cnt == 0) ans = top->right->val;
                    cnt++;
                }
            }
        }
        return ans;
    }
};