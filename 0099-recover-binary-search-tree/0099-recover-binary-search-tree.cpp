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
// class Solution {
// public:
//     TreeNode *prev;
//     TreeNode *middle;
//     TreeNode *first;
//     TreeNode *second;

//     void inorder(TreeNode *root){
//         if(root == NULL) return;
//         inorder(root -> left);
//         if(prev != NULL && root -> val < prev -> val){
//             if(first == NULL){
//                 first = prev;
//                 middle = root;
//             }
//             else second = root;
//         }
//         prev = root;
//         inorder(root -> right);
//     }

//     void recoverTree(TreeNode* root) {
//         middle = first = second = NULL;
//         prev = new TreeNode(INT_MIN);
//         inorder(root);
//         if(first != NULL && second != NULL){
//             int t = first -> val;
//             first -> val = second -> val;
//             second -> val = t;
//         }
//         else if(first != NULL && middle != NULL){
//             int t = first -> val;
//             first -> val = middle -> val;
//             middle -> val = t;
//         }
//     }
// };





class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* second;

    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root -> left);
        
        if(prev != NULL && root -> val < prev -> val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else second = root;
        }
        prev = root;
        inorder(root -> right);
    }


    void recoverTree(TreeNode* root) {
        first = second = prev = middle = NULL;
        // prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && second) swap(first -> val,second -> val);
        else if(first && middle) swap(first -> val,middle -> val);
    }
};