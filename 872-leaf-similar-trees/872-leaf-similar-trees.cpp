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
//     int isSimilar(TreeNode *root1, TreeNode *root2){
//         if((!root1->left && !root1->right) && (!root2->left && root2->right)){
//             if(root1->val != root2->val) return -1;
//         }
//         if(!root1->left && !root2->left){
//             return root2->val;
//         }
//         if(!root2->left && !root2->right){
//             return root1->val;
//         }
        
//         return isSimilar(root1->left, root2->left) && isSimilar(root2->right, root2->right)
        
//     }
    void printLeaf(TreeNode *root, vector<int> &leaf){
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }
        if(root->left) printLeaf(root->left, leaf);
        if(root->right) printLeaf(root->right, leaf);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        printLeaf(root1, leaves1);
        printLeaf(root2, leaves2);
        int n1 = leaves1.size();
        int n2 = leaves2.size();
        if(n1 != n2) return false;
        for(int i = 0 ; i < n1 ; i++){
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};