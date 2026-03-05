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
    vector<vector<int>> bfs (TreeNode *root){
        if(!root)
            return {};
        queue<pair<TreeNode*, int>>q;
        map<int, multiset<pair<int, int>>>mp;
        q.push({root, 0});

        int l=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [curr, a] = q.front();
                q.pop();
                mp[a].insert({l, curr->val});

                if(curr->left !=nullptr)
                    q.push({curr->left, a-1});
                    
                if(curr->right !=nullptr)
                    q.push({curr->right, a+1});
            }
            l++;
        }
        vector<vector<int>>ans;
        for(auto[a,b]: mp){
            vector<int>tmp;
            for(auto [c,d]: b){
                tmp.push_back(d);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return bfs(root);
    }
};