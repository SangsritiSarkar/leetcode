class Solution {
public:
    void func(int ind, int s, vector<int> arr, vector<int> &ds, vector<vector<int>> &ans){
        if(s==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();++i){
            if(i!=ind and arr[i]==arr[i-1]) continue;
            if(arr[i]>s) break;
            ds.push_back(arr[i]);
            func(i+1, s-arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        func(0,target,candidates,ds,ans);
        return ans;
    }
};