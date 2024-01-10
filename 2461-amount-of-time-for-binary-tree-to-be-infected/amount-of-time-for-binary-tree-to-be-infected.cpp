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
    void make_adj(unordered_map<int, vector<int>> &adj, int parent, TreeNode* node)
    {
        if(node==nullptr) return;
        if(parent!=-1)
        {
            adj[node->val].push_back(parent);
        }
        if(node->left)
             adj[node->val].push_back(node->left->val);
        if(node->right) 
            adj[node->val].push_back(node->right->val); 
        make_adj(adj,node->val,node->left); 
        make_adj(adj,node->val,node->right);      
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        make_adj(adj,-1,root);

        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int min=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int node=q.front();
                q.pop();

                for(auto it:adj[node])
                {
                    if(vis.find(it)==vis.end())
                    {
                        vis.insert(it);
                        q.push(it);
                    }

                }
            }
            min++;
        }
        return min-1;
    }
};