class Solution {
public:
    void solve(int ind, vector<int> &ds, set<vector<int>> &s, vector<int> &nums){
        if(ind==nums.size()){
            s.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        solve(ind+1, ds, s, nums);
        ds.pop_back();
        solve(ind+1, ds, s, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ds, s, nums);
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};