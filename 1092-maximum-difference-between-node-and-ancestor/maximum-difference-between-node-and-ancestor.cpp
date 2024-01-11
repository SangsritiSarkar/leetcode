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
    int f(TreeNode* root, int maxi, int mini)
    {
        if(root==nullptr) return abs(maxi-mini);
        maxi=max(maxi,root->val);
        mini=min(mini, root->val);

        int l=f(root->left,maxi,mini);
        int r=f(root->right,maxi,mini);
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
       int maxval=root->val;
       int minval=root->val;
       return f(root, maxval,minval);
    }
};