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
    int dfs(TreeNode* root, bool t)
    {
        if(!root) return 0;
        if(!root->left and !root->right and t!=0) return  t ? root->val : 0;
        return dfs(root->left,true) + dfs(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
 
};