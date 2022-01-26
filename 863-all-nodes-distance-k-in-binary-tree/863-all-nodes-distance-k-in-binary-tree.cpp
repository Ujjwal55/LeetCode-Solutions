/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_Parents(TreeNode *root, TreeNode *target, unordered_map<TreeNode*, TreeNode *> &parents){
        if(root == NULL) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *top = q.front();
            q.pop();
            if(top->left){
                parents[top->left] = top;
                q.push(top->left);
            }
            if(top->right){
                parents[top->right] = top;
                q.push(top->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parents;
        make_Parents(root, target, parents);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            if(cnt++ == k) break;
            for(int i = 0 ; i < n ; i++){
                TreeNode *top = q.front();
                q.pop();
                if(top->left && !visited[top->left]){
                    q.push(top->left);
                    visited[top->left] = true;
                }
                if(top->right && !visited[top->right]){
                    q.push(top->right);
                    visited[top->right] = true;
                }
                if(parents[top] && !visited[parents[top]]){
                    q.push(parents[top]);
                    visited[parents[top]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode *top = q.front();
            q.pop();
            ans.push_back(top->val);
        }
        return ans;
    }
};