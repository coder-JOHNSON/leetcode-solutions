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
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) return NULL;    // return root  (because root == NULL)
//         if(root -> val == key){
//             if(root -> left != NULL && root -> right != NULL){
//                 TreeNode* temp = root -> left;
//                 while(temp -> right != NULL){
//                     temp = temp -> right; 
//                 }
//                 root -> val = temp -> val;
//                 if(root -> left != NULL) root -> left = deleteNode(root -> left,root -> val);
//             }
//             else{
//                 if(root -> left != NULL) return root -> left;
//                 else return root -> right;
//             }
//         }
//         else if(root -> val > key) root -> left = deleteNode(root -> left,key);
//         else root -> right = deleteNode(root -> right,key);
//         return root;
//     }
// };





class Solution {
public:
    TreeNode* max(TreeNode* root){
        while(root -> left != NULL){
            root = root -> left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root -> val == key){
            if(root -> left == NULL && root -> right == NULL) return NULL;
            else if(root -> left == NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            else if(root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            else{
                TreeNode* successor = max(root -> right);
                root -> val = successor -> val;
                root -> right = deleteNode(root -> right,successor -> val);
                return root;
            }
        }
        else if(root -> val > key) root -> left = deleteNode(root -> left,key);
        else root -> right = deleteNode(root -> right,key);
        return root;
    }
};