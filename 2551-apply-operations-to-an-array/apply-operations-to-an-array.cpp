class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
                ++i;
            }
        }
       for(auto it:nums){
        if(it==0) cnt++;
        else ans.push_back(it);
       }
        for(int i=0;i<cnt;++i) ans.push_back(0);
        return ans;
    }
};