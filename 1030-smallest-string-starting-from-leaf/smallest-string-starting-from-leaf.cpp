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
    string smst="";

    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return smst;
    }

    void dfs(TreeNode* root, string curr)
    {
        if(!root) return;

        curr=char(root->val+'a')+curr;
        if(!root->left and !root->right)
          if(smst=="" or curr<smst) smst=curr;
        
        if(root->left) dfs(root->left,curr);
        if(root->right) dfs(root->right, curr);

    }
};