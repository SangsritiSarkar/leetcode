class Solution {
public:
    void solve(int ind, vector<int> &cand, vector<int> &ds, int target, int sum, vector<vector<int>> &ans){
        if(ind==cand.size()){
            if(target==sum) ans.push_back(ds);
            return;
        }
        if(cand[ind]<=target-sum) {
            ds.push_back(cand[ind]);
            solve(ind, cand, ds, target, sum+cand[ind],ans);
            ds.pop_back();
        }
       
        solve(ind+1,cand,ds, target,sum,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,candidates,ds,target,0,ans);
        return ans;
    }
};