class Solution {
public:
//SPACE OPTIMIZATION
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0), curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int notTake=0+next[prev+1];
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev])
                   take=1+next[ind+1]; //COORDINATE SHIFT PREV part
                curr[prev+1]=max(take, notTake);
            }
            next=curr;
            
        }
        return next[0];
       
    }
};