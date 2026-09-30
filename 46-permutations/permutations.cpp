class Solution {
public:
    void func( vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &mp){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=1;
                func(nums, ds, ans, mp);
                ds.pop_back();
                mp[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> mp(nums.size(), 0);
        vector<int> ds;
        vector<vector<int>> ans;
        func(nums, ds, ans, mp);
        return ans;
    }
};