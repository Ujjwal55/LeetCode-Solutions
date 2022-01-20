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
    bool nodesSum(TreeNode *root, int targetSum, TreeNode *prevNode){
        if(targetSum == 0 && root == NULL && prevNode->left == NULL && prevNode->right == NULL)  return true;
        if(root == NULL) return false;
        // if(leftSum == true || rightSum == true) return true;
        return (nodesSum(root->left, targetSum-root->val, root) || nodesSum(root->right, targetSum-root->val, root));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->val == targetSum && root->left == NULL && root->right == NULL) return true;
        TreeNode *firstNode = root;
        return nodesSum(root, targetSum, firstNode);
    }
};