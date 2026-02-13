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
    int mx = INT_MIN;
    int s(TreeNode* root){
        if(!root)
            return 0;
        int ls = s(root->left);
        int rs = s(root->right);
        mx = max(root->val + max(0, ls)+max(0, rs), mx);
        return root->val+max(0, max(ls, rs));
    }
    int maxPathSum(TreeNode* root) {
        s(root);
        return mx;
    }
};