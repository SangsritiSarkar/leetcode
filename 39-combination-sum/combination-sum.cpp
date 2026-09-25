class Solution {
public:
    void func(int ind, vector<int> &ds, int target, vector<int> &arr, vector<vector<int>> &ans){
        if(ind==arr.size()){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            func(ind,ds, target-arr[ind], arr, ans);
            ds.pop_back();
        }
        func(ind+1,ds, target, arr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, ds,target, candidates, ans);
        return ans;
    }
};