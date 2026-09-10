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

    int solve(TreeNode *root,int k){
        if(root == NULL) return 0;
        k = k * 10 + root -> val;
        if(root -> left == NULL && root -> right == NULL) return k;
        int l = solve(root -> left,k);
        int r = solve(root -> right,k);
        return l + r;
    }

    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};