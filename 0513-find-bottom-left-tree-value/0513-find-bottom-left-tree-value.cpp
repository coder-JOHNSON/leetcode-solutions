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
    int findBottomLeftValue(TreeNode* root) {
        stack<int>st;
        queue<TreeNode*>dq;
        dq.push(root);
        if(root == nullptr) return st.top();
        while(dq.size()){
            int n = dq.size();
            for(int i = 0; i < n; i++){
                TreeNode *temp = dq.front();
                dq.pop();
                if(temp -> left != nullptr) dq.push(temp -> left);
                if(temp -> right != nullptr) dq.push(temp -> right);
                if(i == 0) st.push(temp -> val);
            }
        }
        return st.top();
    }
};