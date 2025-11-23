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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push({root, {0,0}});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;++i){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                int ver=it.second.first;
                int lev=it.second.second;
                mp[ver][lev].insert(node->val);
                if(node->left!=nullptr) q.push({node->left,{ver-1,lev+1}});
                if(node->right!=nullptr) q.push({node->right, {ver+1,lev+1}});
            }
        }
        
        for(auto v:mp){
            vector<int> ver;
            for(auto x:v.second){
                ver.insert(ver.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(ver);
        }
        return ans;
    }
};