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

 //Best way

class Solution {
    unordered_map<int, int>mp;
    int postIndex;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if(inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mp[rootVal];

        // IMPORTANT: build right first
        root->right = build(inorder, postorder, inIndex + 1, inEnd);
        root->left = build(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return build(inorder, postorder, 0, n-1);
    }
};


// similar approach but little diff
// class Solution {
//     TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
//         if(inStart>inEnd)
//             return nullptr;
        
//         int rootVal = postorder[postEnd];
//         int i = mp[rootVal];
        
//         int leftSize = i-inStart;
//         int rightSize = inEnd-i;

//         TreeNode *root = new TreeNode(rootVal);
//         root->left = solve(inorder, postorder, inStart, i-1, postStart, postStart+leftSize-1);
//         root->right = solve(inorder, postorder, i+1, inEnd, postEnd-rightSize, postEnd-1);

//         return root;
//     }
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size();

//         for(int i=0; i<n; i++)
//             mp[inorder[i]] = i;

//         int inStart = 0, inEnd = n-1;
//         int postStart = 0, postEnd=n-1;
//         return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
//     }
// };