class Solution {
public:

    void func(int ind, int target, vector<vector<int>> &ans, vector<int> &cand, vector<int> &ds){
        if(ind==cand.size()){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(cand[ind]<=target){
            ds.push_back(cand[ind]);
            func(ind, target-cand[ind], ans, cand, ds);
            ds.pop_back();
        }
        func(ind+1, target, ans,cand,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,target,ans,candidates,ds);
        return ans;
    }
};