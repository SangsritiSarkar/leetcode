class Solution {
public:
    void func(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &cand){
        if(target==0) {ans.push_back(ds); return;}
        for(int i=ind; i<cand.size(); ++i){
            if(i>ind and cand[i]==cand[i-1]) continue;
            if(cand[i]<=target){
                ds.push_back(cand[i]);
                func(i+1, target-cand[i], ds,ans,cand);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,target,ds,ans,candidates);
        return ans;
    }
};