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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        long long ans=0;
        if(root==nullptr) return ans;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            long long min=q.front().second;
            long long st,last;
            for(int i=0;i<s;++i){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                long long num=it.second-min;
                if(i==0) st=num;
                if(i==s-1) last=num;
                if(node->left) q.push({node->left, 2*num+1});
                if(node->right) q.push({node->right, 2*num+2});
            }
            ans=max(ans,last-st+1);
        }
        return ans;
    }
};