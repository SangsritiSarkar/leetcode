class Solution {
public:
    void solve(int ind, int target, vector<int> &ds, vector<int> &cand, vector<vector<int>> &ans){
        if(ind==cand.size())
        {
            if(target==0) ans.push_back(ds);
            return;
        }
        if(target>=cand[ind]){
            ds.push_back(cand[ind]);
            solve(ind,target-cand[ind], ds,cand, ans);
            ds.pop_back();
        }
        solve(ind+1, target, ds, cand, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,target,ds,candidates,ans);
        return ans;
    }
};