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
    void printVertical(TreeNode *root, vector<vector<int>> &ans){
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode *curr = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(curr->left){
                q.push({curr->left, {x-1, y+1}});
            }
            if(curr->right){
                q.push({curr->right, {x+1, y+1}});
            }
            m[x][y].insert(curr->val);
        }
        for(auto it: m){
            vector<int> col;
            for(auto p: it.second){
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        printVertical(root, ans);
        return ans;
    }
};