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
    map<int, int>mp;
    int level;
    void bfs(TreeNode *root){
        if(!root)
            return;
        level = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto curr = q.front();
                mp[level] = curr->val;
                q.pop();

                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right !=nullptr)
                    q.push(curr->right);
            }
            level++;
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);

        vector<int>ans;
        for(auto &[a,b]: mp)
            ans.push_back(b);

        return ans;
    }
};