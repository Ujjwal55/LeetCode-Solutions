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
    long long inf = 1e18;
    
    bool valid(TreeNode* root,long long L,long long R){
        if(root==NULL) return true;
        
        long long x = root->val;
        if(x>=R || x<=L) return false;
        
        return valid(root->left,L,min(x,R)) && valid(root->right,max(L,x),R);
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root,-inf,inf);
    }
};