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
    void cousins(TreeNode *root, int x, int y, int level, int parent, int *treeLevel, int *treeParents){
        if(root == NULL) return;
        if(root->val == x){
            treeLevel[0] = level;
            treeParents[0] = parent;
        }
        if(root->val == y){
            treeLevel[1] = level;
            treeParents[1] = parent;
        }
        cousins(root->left, x, y, level+1, root->val, treeLevel, treeParents);
        cousins(root->right, x, y, level+1, root->val, treeLevel, treeParents);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int treeLevel[2] = {-1,-1};
        int treeParents[2] = {-1, -1};
        cousins(root, x, y, 0, -1, treeLevel, treeParents);
        if(treeLevel[0] == treeLevel[1] && treeParents[0] != treeParents[1]) return true;
        return false;
    }
};