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
    // inorder predecessor can also be used
    // inorder successor  (smallest value in right subtree)
    TreeNode* getSuccessor(TreeNode* curr){
        curr = curr->right;
        while(curr != nullptr && curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else{
            // for root with 0 or 1 child
            if(root->left == nullptr){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == nullptr){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // for root having 2 childs
            TreeNode *succ = getSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val); // this will fall into root with 0 or 1 children
        }
        return root;
    }
};