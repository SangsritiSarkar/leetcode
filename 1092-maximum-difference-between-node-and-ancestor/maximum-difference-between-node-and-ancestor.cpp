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
    int diff=INT_MIN;
    void f(TreeNode* root, TreeNode* child)
    {
        if(root==nullptr || child==nullptr) return;
        diff=max(diff,abs(root->val - child->val));
        f(root,child->left);
        f(root,child->right);

    }
    void f1(TreeNode* root)
    {
        if(root==nullptr) return ;
        f(root,root->left);
        f(root, root->right);
        f1(root->left);
        f1(root->right); 

    }
    int maxAncestorDiff(TreeNode* root) {
        //int diff=-1;
        f1(root);
        return diff;
    }
};