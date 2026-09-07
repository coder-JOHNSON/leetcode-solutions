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
    // int height(TreeNode *root){
    //     if(root == nullptr) return 0;
    //     int l = height(root -> left);
    //     if(l == -1) return -1;
    //     int r = height(root -> right);
    //     if(r == -1) return -1;
    //     if(abs(l - r) > 1) return -1;
    //     return max(l,r) + 1;
    // }

    // bool isBalanced(TreeNode* root) {
    //     return height(root) != -1;
    // }

    int levels(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(levels(root -> left),levels(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftLevels = levels(root -> left);
        int rightLevels = levels(root -> right);
        if(abs(leftLevels - rightLevels) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};