class Solution {
public:

    void solve(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();++i){
            swap(nums[i],nums[ind]);
            solve(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};