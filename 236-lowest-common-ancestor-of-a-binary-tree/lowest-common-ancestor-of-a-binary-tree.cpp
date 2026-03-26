/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
            
        if(root == p || root == q)
            return root;
        
        auto leftN = lowestCommonAncestor(root->left, p, q);
        auto rightN = lowestCommonAncestor(root->right, p, q);

        if(leftN != nullptr && rightN != nullptr)
            return root;

        if(leftN == nullptr)
            return rightN;
        else
            return leftN;
    }
};