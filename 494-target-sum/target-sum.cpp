class Solution {
public:
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(auto it:arr) totsum+=it;
    if(totsum-d < 0 ) return 0;
    else if((totsum-d)%2 !=0) return 0;
   
    int s2=(totsum-d)/2;
    vector<vector<int>> dp(n, vector<int> (s2+1, 0));

    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1; //not take as sum=0 but arr[0]!=0

    if(arr[0]!=0 && arr[0]<=s2) dp[0][arr[0]]=1; //take

    for(int ind=1;ind<n;ind++)
    {
        for(int target=0;target<=s2;target++)
        {
            int notTake=dp[ind-1][target];
            int take=0;
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=(take+notTake);
        }
    }
    return dp[n-1][s2];
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};