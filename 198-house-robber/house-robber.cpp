class Solution {
public:
//RECURSIOIN
    // int f(int ind,vector<int> &nums)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     int pick=nums[ind]+f(ind-2,nums);
    //     int notpick=0+f(ind-1,nums);
    //     return max(pick,notpick);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     int ans=f(n-1,nums);
    //     return ans;
    // }


//MEMOIZATION
    // int f(int ind, vector<int> &nums, vector<int> &dp)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];

    //     int pick=nums[ind]+f(ind-2,nums,dp);
    //     int notpick=0+f(ind-1,nums,dp);
    //     return dp[ind]=max(pick,notpick);
    // }
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     int ans=f(n-1,nums,dp);
    //     return ans;

    // }

//TABULATION 
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     int i;
    //     vector<int> dp(n);
    //     dp[0]=nums[0];
    //     for(i=1;i<n;i++)
    //     {
    //         int pick=nums[i]; if(i>1) pick+=dp[i-2];
    //         int notpick=0+dp[i-1];

    //         dp[i]=max(pick,notpick);
    //     }
    //     return dp[i-1];
        
    //  }


//SPACE OPTIMIZATION  
       int rob(vector<int>& nums){
           int n=nums.size();
           int prev=nums[0];
           int prev2=0;
           for(int i=1;i<n;i++)
           {
               int pick=nums[i];
               if(i>1) pick+=prev2;
               int nonpick=0+prev;
               int curr=max(pick,nonpick);

               prev2=prev;
               prev=curr;
           }
           return prev;
       }
};