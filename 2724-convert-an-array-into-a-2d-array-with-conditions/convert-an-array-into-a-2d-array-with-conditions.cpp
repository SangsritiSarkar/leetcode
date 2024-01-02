class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int> freq;
       vector<vector<int>> ans;
       for(int i=0;i<n;i++)
       {
           int count=freq[nums[i]];
           if(ans.size()==count)
           {
               ans.push_back({});
           }
           ans[count].push_back(nums[i]);
           freq[nums[i]]++;

       }
       return ans;
        
    }

    
};