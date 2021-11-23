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
    int treeHeight(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    int isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if ((abs(treeHeight(root->left) - treeHeight(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        else{
            return false;
        }
    }
};