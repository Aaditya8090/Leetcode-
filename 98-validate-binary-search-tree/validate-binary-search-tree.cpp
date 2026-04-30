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
    vector<int>in;
    void ino(TreeNode *root){
        if(!root)return;
        ino(root->left);
        in.push_back(root->val);
        ino(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        ino(root);
        int prev=in[0];
        for(int i=1; i<in.size(); i++){
            if(in[i]==prev)
                return false;
            else
                prev=in[i];
            if(in[i]<in[i-1])
                return false;
        }
        return true;
    }
};