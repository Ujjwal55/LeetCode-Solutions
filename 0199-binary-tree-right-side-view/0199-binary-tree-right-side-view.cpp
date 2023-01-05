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
    void printLevelOrder(TreeNode *root, vector<int> &ans){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                TreeNode *top = q.front();
                q.pop();
                if(cnt < 1){ 
                    ans.push_back(top->val);
                    cnt++;
                }
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }
    } 
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        printLevelOrder(root, ans);
        return ans;
    }
};