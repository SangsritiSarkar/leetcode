class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int num=0; num<=(1<<n)-1;++num){
            vector<int> ds;
            for(int i=0;i<n;++i){
                if(num&(1<<i)) ds.push_back(nums[i]);
            }
            s.insert(ds);
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};