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
    int bfs(TreeNode *root){
        if(!root)
            return 0;

        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});

        int ans=0;

        while(!q.empty()){
            int size = q.size();

            auto [node, l] = q.front();
            long long ll=-1, r=-1;
            
            for(int i=0; i<size; i++){
                auto [a,b] = q.front();
                q.pop();

                long long currIdx = b-l;

                // if(i==0)
                //     ll = currIdx;
                // if(i == size-1)
                //     r = currIdx;

                ans = max((int)(b-l+1), ans);

                if(a->left)
                    q.push({a->left, 2*currIdx});

                if(a->right)
                    q.push({a->right, 2*currIdx+1});
            }
            // ans = max((int)(r-ll+1), ans);
        }
        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};