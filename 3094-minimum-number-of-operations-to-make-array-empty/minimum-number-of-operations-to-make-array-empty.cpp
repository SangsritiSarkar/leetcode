class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it:mp)
        {
            int x=it.second;
           if(x==1) return -1;
           ans+=x/3;
           if(x%3!=0) ans++;
        }
        return ans;
    }
};