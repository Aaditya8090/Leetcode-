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
    unordered_map<TreeNode*, vector<TreeNode*>>g;

    void build(TreeNode *node, TreeNode *parent){
        if(!node)
            return;
        
        if(parent){
            g[node].push_back(parent);
            g[parent].push_back(node);
        }
        
        build(node->left, node);
        build(node->right, node);
    }

    vector<int> bfs(TreeNode *root, int &k){
        if(!root) return {};

        vector<int>ans;
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        
        q.push(root);
        visited.insert(root);

        int level=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto curr = q.front();
                q.pop();

                ans.push_back(curr->val);

                for(auto fr: g[curr] ){
                    if(!visited.count(fr)){
                        visited.insert(fr);
                        q.push(fr);
                    }
                }
            }
            
            if(level == k) return ans;
            ans.clear();
            level++;
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // map child to it parent to convert it into graph
        build(root, nullptr);
        return bfs(target, k);
    }
};

// little diff way
// class Solution {
//     vector<int>ans;
//     unordered_map<TreeNode* ,TreeNode*>par;

//     void pre(TreeNode *root){
//         if(!root)
//             return;
        
//         if(root->left){
//             par[root->left] = root;
//             pre(root->left);
//         }
//         if(root->right){
//             par[root->right] = root;
//             pre(root->right);
//         }
//     }

//     void bfs(TreeNode *root, int &k){
//         if(!root) return;

//         unordered_set<TreeNode*>visited;
//         queue<TreeNode*>q;

//         q.push(root);
//         visited.insert(root);

//         int level=0;
//         while(!q.empty()){
//             int size =  q.size();
//             for(int i=0; i<size; i++){
//                 auto curr = q.front();
//                 q.pop();

//                 if(level == k)
//                     ans.push_back(curr->val);

//                 if(curr->left && visited.count(curr->left)==0){
//                     visited.insert(curr->left);
//                     q.push(curr->left);
//                 }

//                 if(curr->right && visited.count(curr->right)==0){
//                     visited.insert(curr->right);
//                     q.push(curr->right);
//                 }

//                 if(par.count(curr) && visited.count(par[curr])==0){
//                     visited.insert(par[curr]);
//                     q.push(par[curr]);
//                 }
//             }

//             if(level == k) break;
//             level++;
//         }
//     }
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         // map child to it parent to convert it into graph
//         pre(root);
//         bfs(target, k);
//         return ans;
//     }
// };