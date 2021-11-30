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
    int treeHeight(TreeNode *root, int &maxi){
        if(root == NULL){
            return 0;
        }
        int leftHeight = treeHeight(root->left, maxi);
        int rightHeight = treeHeight(root->right, maxi);
        maxi = max(maxi, leftHeight+rightHeight);
        return 1 + max(leftHeight, rightHeight);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int height = treeHeight(root, maxi);    
        return maxi;
    }
};