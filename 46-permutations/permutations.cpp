class Solution {
public:

    void solve(vector<int> &ds, map<int,int> &mp, vector<int> &nums, vector<vector<int>> &ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=1;
                solve(ds,mp,nums,ans);
                ds.pop_back();
                mp[i]=0;
                
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();++i) mp[i]=0;
        solve(ds,mp,nums, ans);
        return ans;
    }
};