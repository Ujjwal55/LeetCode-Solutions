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
    int leftSum(TreeNode *root, bool isLeft){
        if(!root->left && !root->right && isLeft){
            return root->val;    
        }
        int left = 0;
        int right = 0;
        if(root->left) left = leftSum(root->left, true);
        if(root->right) right = leftSum(root->right, false);
        // sum=left;
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return leftSum(root, false);
        
    }
};