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
    // iterative inorder
    vector<int>itIn(TreeNode* root){
        vector<int>ans;
        if(!root)
            return ans;
        
        stack<TreeNode*>s;
        TreeNode* curr =  root;
        while(curr || !s.empty()){
            while(curr!=nullptr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }

    // recursive inorder
    void in(TreeNode* root, vector<int>&a){
        if(!root)
            return;
        in(root->left, a);
        a.push_back(root->val);
        in(root->right, a);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // in(root, ans);
        // return ans;

        return itIn(root);
    }
};