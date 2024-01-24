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
    int res=0;
    void solve(TreeNode* root, vector<int>& mp)
    {
        if(root!=NULL) {mp[root->val]++;
        if(root->left==nullptr && root->right==nullptr)
        {
            int oddf=0;
            for(int i=1;i<=9;i++)
            {
                if(mp[i]&1) oddf++;
            }
            res+=oddf<=1;
        }
        solve(root->left,mp);
        solve(root->right,mp);

        mp[root->val]--;
        }

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10,0);
        solve(root,mp);
        return res;
      
    }
};