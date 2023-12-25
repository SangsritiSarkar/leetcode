class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size()%3 !=0) return {};
       
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0,j;
        while(i<nums.size())
        {
            vector<int> v;
            int x=nums[i]+k;
            for(j=i;j<nums.size();j++)
            {
                if(v.size()==3) break;
                else if(nums[j]<=x)
                {
                    v.push_back(nums[j]);
                }
            }
            if(v.size() !=3) return {};
            else ans.push_back(v);
            i=j;
            
        }
        return ans;
    }
};