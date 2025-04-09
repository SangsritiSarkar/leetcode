class Solution {
public:

    void solve(int ind, vector<int> &ds, int target, int k, vector<vector<int>> &ans)
    {
        if(ds.size()==k)
        {
            if(target==0)  ans.push_back(ds);
            return;
        }
        for(int i=ind; i<=9;++i){
            if(target>=i){
                ds.push_back(i);
                solve(i+1, ds, target-i, k, ans);
                ds.pop_back();
            } 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(1, ds, n, k, ans);
        return ans;
    }
};