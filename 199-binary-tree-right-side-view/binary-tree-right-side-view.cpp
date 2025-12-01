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

    void f(TreeNode* node, int lev, vector<int> &ds){
        if(node==nullptr) return;
        if(lev==ds.size()) ds.push_back(node->val);
        f(node->right,lev+1,ds);
        f(node->left,lev+1,ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        vector<int> ds;
        f(root,0,ds);
        return ds;
    }
};