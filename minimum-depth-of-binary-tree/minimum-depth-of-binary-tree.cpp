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
        if(root!= NULL && root->left == NULL){
            return 1+treeHeight(root->right);
        }
        if(root!=NULL && root->right == NULL){
            return 1+treeHeight(root->left);
        }
        else if (root == NULL){
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        leftHeight += treeHeight(root->left);
        rightHeight += treeHeight(root->right);
        return 1 + min(leftHeight, rightHeight);
    }
    int minDepth(TreeNode* root) {
        return treeHeight(root);
    }
};