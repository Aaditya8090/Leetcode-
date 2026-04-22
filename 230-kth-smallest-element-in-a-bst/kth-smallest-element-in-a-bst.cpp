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
    int ans;
    void in(TreeNode *root, int &k){
        if(!root)return;
        in(root->left, k);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        in(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        in(root, k);
        return ans;
    }
};