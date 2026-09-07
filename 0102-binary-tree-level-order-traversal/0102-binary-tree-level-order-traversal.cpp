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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> ans;
    //     vector<int> level;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     if(root == nullptr) return ans;

    //     while(q.size() > 0){
    //         int n = q.size();
    //         level.clear();

    //         for(int i = 0; i < n; i++){
    //              TreeNode *temp = q.front();
    //              q.pop();

    //              if(temp -> left != nullptr){
    //                 q.push(temp -> left);
    //              }
    //              if(temp -> right != nullptr){
    //                 q.push(temp -> right);
    //              }
    //              level.push_back(temp -> val);
    //         }
    //         ans.push_back(level);
    //     }
    //     return ans;
    // }

    int levels(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(levels(root -> left),levels(root -> right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n,vector<int>(0));
        queue<pair<TreeNode*,int>>q;
        if(root != NULL) q.push({root,0});
        while(q.size() > 0){
            pair<TreeNode*,int> front = q.front();
            q.pop();
            TreeNode *node = front.first;
            int lvl = front.second;
            ans[lvl].push_back(node -> val);
            if(node -> left != NULL) q.push({node -> left,lvl + 1});
            if(node -> right != NULL) q.push({node -> right,lvl + 1});
        }
        return ans;
    }
};