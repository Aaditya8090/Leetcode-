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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool inv = false;
        while(!q.empty()){
            vector<int>v;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
            if(inv){
                reverse(v.begin(), v.end());
                ans.push_back(v);
                inv = false;
            }else{
                ans.push_back(v);
                inv = true;
            }
        }
        return ans;
    }
};