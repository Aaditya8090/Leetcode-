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
    // iterative Post using 1 stack
    vector<int>itPost(TreeNode* root){
        vector<int>ans;
        if(!root)
            return ans;

        stack<TreeNode*>s;
        TreeNode* curr = root, *prev=nullptr;
        while(curr || !s.empty()){
            while(curr!=nullptr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            if(curr->right != nullptr || curr->right != prev){
                curr = curr->right;
            }else{
                s.pop();
                ans.push_back(curr->val);
                prev = curr;
                curr=nullptr;
            }
        }
        return ans;
    }
    void post(TreeNode* root, vector<int>&a){
        if(!root)
            return;
        post(root->left, a);
        post(root->right, a);
        a.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        post(root, ans);
        return ans;
    }
};