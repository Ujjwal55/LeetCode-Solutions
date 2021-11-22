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
    TreeNode* buildtreeHelper(vector<int> &pre, vector<int> &in, int preS, int preE, int inS, int inE){
        if(preS > preE){
            return NULL;
        }
        int rootData = pre[preS];
        int rootIdx = -1;
        for(int i = 0 ; i < in.size() ; i++){
            if(in[i] == rootData){
                rootIdx = i;
                break;
            }
        }
        int lpreS = preS + 1;
        int rpreE = preE;
        int linS = inS;
        int linE = rootIdx - 1;
        int rinS = rootIdx + 1;
        int rinE = inE;
        int lpreE = linE - linS + lpreS;
        int rpreS = lpreE + 1;
        TreeNode *root = new TreeNode(rootData);
        root->left = buildtreeHelper(pre, in, lpreS, lpreE, linS, linE);
        root->right = buildtreeHelper(pre, in, rpreS, rpreE, rinS, rinE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildtreeHelper(preorder, inorder, 0, n-1, 0, n-1);
    }
};