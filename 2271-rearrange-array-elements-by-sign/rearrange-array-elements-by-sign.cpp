class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,pos,neg;
        
        for(auto it:nums)
        {
            if(it>0 ) pos.push_back(it);
            else neg.push_back(it);
            
        }
        for(int i=0;i<n/2;i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};