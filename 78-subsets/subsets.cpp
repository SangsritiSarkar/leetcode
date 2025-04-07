class Solution {
public:
    void func(int ind, vector<int> &ds, int n, vector<vector<int>> &ans, vector<int>& nums){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        //pick
        ds.push_back(nums[ind]);
        func(ind+1, ds, n , ans, nums);
        ds.pop_back();
        //not pick
        func(ind+1,ds,n,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,ds,n,ans,nums);
        return ans;
    }
};