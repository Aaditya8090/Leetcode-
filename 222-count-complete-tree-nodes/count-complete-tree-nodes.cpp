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
    int pre(TreeNode *root){
        if(!root)
            return 0;
        return 1+pre(root->left)+pre(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        return pre(root);
    }
};