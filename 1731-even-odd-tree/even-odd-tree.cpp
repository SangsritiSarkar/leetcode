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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lev=0;
        while(!q.empty())
        {
            int size=q.size();
            
            int val=(lev&1)?INT_MAX:INT_MIN;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if((node->val&1) == (lev&1)) return false;
                if((lev&1 and node->val>=val) or (!(lev&1) and node->val<=val)) return false;
                val=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            lev++;
        }
        return true;
    }



};