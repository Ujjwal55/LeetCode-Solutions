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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool toggle = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0 ; i < n ; i++){
                TreeNode *top = q.front();
                q.pop();
                if(toggle) temp[i] = top->val;
                else temp[n-i-1] = top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            toggle = !toggle;
            ans.push_back(temp);
        }
        return ans;
    }
};