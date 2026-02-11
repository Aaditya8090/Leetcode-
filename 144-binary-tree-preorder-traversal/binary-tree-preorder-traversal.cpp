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
    // iterative preOrder
    vector<int> itPre(TreeNode*root){
        vector<int>v;
        if(!root)
            return v;

        stack<TreeNode*>s;
        s.push(root);

        while(!s.empty()){
            auto curr = s.top();
            s.pop();

            v.push_back(curr->val);

            if(curr->right)
                s.push(curr->right);

            if(curr->left)
                s.push(curr->left);
        }
        return v;
    }

    // Recursive preorder
    void pre(TreeNode* root, vector<int>&a){
        if(root==nullptr)
            return;
        a.push_back(root->val);
        pre(root->left, a);
        pre(root->right, a);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // pre(root, ans);
        // return ans;

        return itPre(root);
    }
};