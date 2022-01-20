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
    void printPath(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> &temp){
        if(root == NULL) return;
        if(targetSum == root->val && root->left == NULL && root->right == NULL){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        printPath(root->left, targetSum-root->val, ans, temp);
        printPath(root->right, targetSum-root->val, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        printPath(root, targetSum, ans, temp);
        return ans;
    }
};