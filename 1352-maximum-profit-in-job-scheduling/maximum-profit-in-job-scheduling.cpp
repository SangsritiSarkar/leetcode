class Solution {
public:
    int getNextInd(vector<vector<int>> &arr, int ind, int currET, int n)
    {
        return lower_bound(begin(arr),end(arr),currET, [&](const auto& a, int val){
            return a[0]<val;
        })-begin(arr);
        
    }
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        
        int n=profit.size();
        vector<vector<int>> arr(n, vector<int> (3,0));
        
        for(int i=0;i<n;i++)
        {
            
            arr[i][0]=st[i];
            arr[i][1]=et[i];
            arr[i][2]=profit[i];
        }
        auto compa=[&](vector<int>& a, vector<int>& b){
           return a[0]<=b[0];
        };
        sort(arr.begin(),arr.end());
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            int nextInd=getNextInd(arr,ind+1,arr[ind][1],n);
            int take=arr[ind][2] +dp[nextInd];
            int notTake=0 + dp[ind+1];
            dp[ind]=max(take, notTake);

        }
        return dp[0];
    }
};






