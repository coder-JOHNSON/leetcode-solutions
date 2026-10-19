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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL) return ans;
        
        while(!q.empty()){
            int n = q.size();
            level.clear();
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp -> val);
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};