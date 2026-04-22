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
    void search(TreeNode* root, int &k){
        if(!root)return;
        if(root->val >= k){
            if(root->left == nullptr){
                root->left = new TreeNode(k);
                return;
            }
            search(root->left, k);
        }else if(root->val <k){
            if(root->right == nullptr){
                root->right = new TreeNode(k);
                return;
            }
            search(root->right, k);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        search(root, val);
        if(root == nullptr)root= new TreeNode(val);
        return root;
    }
};