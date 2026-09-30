class Solution {
public:
    void func(vector<int> &ds, vector<int> &mp, vector<vector<int>> &ans, vector<int> &nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();++i){
            // if marked skip
            // if not marked, check if it's prev is same as this and if the prev already marked, then skip
            if((mp[i]) or (i>0 and nums[i]==nums[i-1] and mp[i-1])) continue; 
                ds.push_back(nums[i]);
                mp[i]=1;
                func(ds, mp, ans, nums);
                ds.pop_back();
                mp[i]=0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> mp(nums.size(),0);
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        func(ds, mp, ans, nums);
        return ans;
    }
};