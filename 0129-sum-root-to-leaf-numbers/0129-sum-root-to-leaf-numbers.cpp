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
    void sum(TreeNode *root, string s, int &ans){
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans += stoi(s);
            return;
        }
        s+=to_string(root->val);
        if(root->left)
            sum(root->left, s, ans);
        if(root->right) sum(root->right, s, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sum(root, "", ans);
        return ans;
    }
};