class Solution {
public:
    void solve(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &cand){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<cand.size();++i){
            if(i!=ind and cand[i]==cand[i-1]) continue; //if i==ind it is okay
            if(target>=cand[i]) {
                ds.push_back(cand[i]);
                solve(i+1, target-cand[i], ds, ans, cand);
                ds.pop_back();
            }

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        //set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target, ds, ans, cand);
        return ans;
    }
};