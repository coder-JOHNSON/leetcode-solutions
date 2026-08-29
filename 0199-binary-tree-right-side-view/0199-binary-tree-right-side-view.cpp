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
    vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> dq;
    vector<int> v;
    if(root == nullptr) return v;
    dq.push(root);
    v.push_back(root -> val);
        while(dq.size()){
            int n = dq.size();
            for(int i = 0; i < n; i++){
                TreeNode *temp = dq.front();
                dq.pop();
                if(temp -> left != nullptr) dq.push(temp -> left);
                if(temp -> right != nullptr) dq.push(temp -> right);
            }
                v.push_back(dq.back() -> val);
        }
        v.pop_back();
        return v;
    }
};