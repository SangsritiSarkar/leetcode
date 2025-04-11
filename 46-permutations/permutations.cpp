class Solution {
public:

    void solve(vector<int> &ds, vector<int> &vis, vector<vector<int>> &ans, vector<int> &nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i]=1;
                solve(ds, vis, ans, nums);

                ds.pop_back();
                vis[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds, vis(nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();++i) vis[i]=0;
        solve(ds, vis, ans, nums);
        return ans;
        
    }
};