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
    // vector<int> rightSideView(TreeNode* root) {
    // queue<TreeNode*> dq;
    // vector<int> v;
    // dq.push(root);
    // if(root == nullptr) return v;
    //     while(dq.size()){
    //         int n = dq.size();
    //         for(int i = 0; i < n; i++){
    //             TreeNode *temp = dq.front();
    //             dq.pop();
    //             if(temp -> left != nullptr) dq.push(temp -> left);
    //             if(temp -> right != nullptr) dq.push(temp -> right);
    //             if(i == n - 1) v.push_back(temp -> val);
    //         }
    //     }
    //     return v;

    int levels(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(levels(root -> left),levels(root -> right));
    }
    void preorder(TreeNode *root,int lvl, vector<int> &ans){
        if(root == NULL) return;
        ans[lvl] = root -> val;
        preorder(root -> left,lvl + 1,ans);
        preorder(root -> right,lvl + 1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
       int n = levels(root);
       vector<int> ans(n);
       preorder(root,0,ans);
       return ans;
    }
};