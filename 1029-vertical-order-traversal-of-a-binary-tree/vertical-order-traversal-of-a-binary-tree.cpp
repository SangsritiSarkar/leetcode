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
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            TreeNode* node=n.first;
            int v=n.second.first, l=n.second.second;
            nodes[v][l].insert(node->val);
            if(node->left) q.push({node->left, {v-1,l+1}});
            if(node->right) q.push({node->right, {v+1, l+1}});
        }
        vector<vector<int>> ans;
        for(auto a:nodes){
            vector<int> col;
            for(auto it:a.second){
                col.insert(col.end(), it.second.begin(),it.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};