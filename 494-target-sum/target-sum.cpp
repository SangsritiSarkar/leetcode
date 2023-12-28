class Solution {
public:
    //SPACE OPTIMIZATION
    int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(auto it:arr) totsum+=it;
    if(totsum-d < 0 ) return 0;
    else if((totsum-d)%2 !=0) return 0;
   
    int s2=(totsum-d)/2;
    vector<int> prev(s2+1,0);
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1; //not take as sum=0 but arr[0]!=0

    if(arr[0]!=0 && arr[0]<=s2) prev[arr[0]]=1; //take

    for(int ind=1;ind<n;ind++)
    {
        for(int target=s2;target>=0;target--)
        {
            int notTake=prev[target];
            int take=0;
            if(arr[ind]<=target) take=prev[target-arr[ind]];

            prev[target]=(take+notTake);
        }
        
    }
    return prev[s2];
    
  }
 int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }

};