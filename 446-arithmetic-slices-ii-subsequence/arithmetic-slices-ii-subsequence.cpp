class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long, int>mp[n];
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff=(long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                int ctj= it==end(mp[j])?0 : it->second;
                mp[i][diff]+=ctj+1;
                res+=ctj;
            }
        }
        return res;
    }
};