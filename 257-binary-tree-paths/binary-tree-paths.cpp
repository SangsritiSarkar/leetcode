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
    void f(TreeNode* node, string t, vector<string> &ans)
    {
        if(node->left==nullptr and node->right==nullptr){
            ans.push_back(t);
            return;
        }
        if(node->left) f(node->left,t+"->"+to_string(node->left->val),ans);
        if(node->right) f(node->right,t+"->"+to_string(node->right->val),ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==nullptr) return ans;
        f(root,to_string(root->val),ans);
        return ans;
    }
};