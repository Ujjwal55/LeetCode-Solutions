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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return max(max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)), leftHeight+rightHeight);
    }
};