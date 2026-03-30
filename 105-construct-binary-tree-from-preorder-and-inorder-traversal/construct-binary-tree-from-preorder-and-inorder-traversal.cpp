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

// Best Way
class Solution {
    unordered_map<int,int> mp;
public:
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if(inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mp[rootVal];

        root->left = build(preorder, inorder, inStart, inIndex - 1);
        root->right = build(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, inorder, 0, n-1);
    }
};


// similar approach but little diff

// class Solution {
//     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
//         if(start>end)
//             return nullptr;
        
//         int rootVal = preorder[idx];

//         int i=start;
//         for(; i<end; i++){
//             if(inorder[i] == rootVal)
//                 break;
//         }
//         ++idx;

//         TreeNode *root = new TreeNode(rootVal);
//         root->left = solve(preorder, inorder, start, i-1, idx);
//         root->right = solve(preorder, inorder, i+1, end, idx);

//         return root;
//     }
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = inorder.size();

//         int idx=0;
//         return solve(preorder, inorder, 0, n-1, idx);
//     }
// };