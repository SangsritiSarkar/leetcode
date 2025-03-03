class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1,v2,ans;
        int n=nums.size(), cnt=0;
        for(auto it:nums) {
            if(it<pivot) v1.push_back(it);
            
            else if(it>pivot) v2.push_back(it);
            else cnt++;
        }
        for(auto it:v1) ans.push_back(it);
        for(int i=1;i<=cnt;++i) ans.push_back(pivot);
        for(auto it:v2) ans.push_back(it);
        return ans;
    }
};