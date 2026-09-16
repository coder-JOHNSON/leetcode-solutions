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
    int totalTilt = 0;
    int calculateSubtreeSum(TreeNode *root){
        if(root == NULL) return 0;
       
        int l = calculateSubtreeSum(root -> left);
        int r = calculateSubtreeSum(root -> right);
        int currentTilt = abs(l - r);
        totalTilt += currentTilt;
        return root -> val + l + r;
    }

    int findTilt(TreeNode* root) {
        totalTilt = 0;    // reset for each call
        calculateSubtreeSum(root);
        return totalTilt;
    }
};