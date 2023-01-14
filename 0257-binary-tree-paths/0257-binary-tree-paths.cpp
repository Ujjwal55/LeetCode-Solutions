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
    void paths(TreeNode *root, vector<string> &ans, string s){
        if(root == NULL) return;
        
        if(!root->left && !root->right){
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        if(!root->right){
            
            s += to_string(root->val) + "->";
            paths(root->left, ans, s);
        }
        if(!root->left){
            s += to_string(root->val) + "->";
            paths(root->right, ans, s);
        }
        if(root->left && root->right){
            s += to_string(root->val) + "->";
            paths(root->left, ans, s);
            paths(root->right, ans, s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        string s;
        paths(root, ans, "");
        return ans;
    }
};