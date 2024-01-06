/*class Solution {
public:
    int getNextInd(vector<vector<int>> &arr, int ind, int currET, int n)
    {
        int h=n-1;
        int l=0, ans=n+1;
        while(l<=h)
        {
            int mid=(l+(h-l))/2;
            if(arr[mid][0]>=currET)
            {
                ans=mid; h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
    }
    int f(int ind, vector<vector<int>> &arr, int n)
    {
       if(ind>=n) return 0;
       int nextInd=getNextInd(arr,ind+1,arr[ind][1],n);
       
       int take=arr[ind][2] +f(nextInd,arr,n);
       int notTake=0 + f(ind+1 , arr, n);
       return max(take, notTake);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        
        int n=profit.size();
        vector<vector<int>> arr(n, vector<int> (3,0));
        
        for(int i=0;i<n;i++)
        {
            // vector<int> temp;
            // for(int j=0;j<3;j++)
            // {
            //     temp={st[j],et[j],profit[j]};
            // }
            // arr.push_back(temp);
            arr[i][0]=st[i];
            arr[i][1]=st[i];
            arr[i][2]=st[i];
        }
        auto compa=[&](vector<int>& a, vector<int>& b){
           return a[0]<=b[0];
        };
        sort(arr.begin(),arr.end());
        return f(0,arr,n);
    }
};
*/
class Solution {
public:
    int getNextInd(vector<vector<int>> &arr, int ind, int currET, int n) {
        int h = n - 1;
        int l = 0, ans = n + 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid][0] >= currET) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int f(int ind, vector<vector<int>> &arr, int n, vector<int>& dp) {
        if (ind >= n)
            return 0;
        if(dp[ind]!=-1) return dp[ind];
        int nextInd = getNextInd(arr, ind + 1, arr[ind][1], n);

        int take = arr[ind][2] + f(nextInd, arr, n,dp);
        int notTake = 0 + f(ind + 1, arr, n,dp);
        return dp[ind]=max(take, notTake);
    }

    int jobScheduling(vector<int> &st, vector<int> &et, vector<int> &profit) {
        int n = profit.size();
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            arr[i][0] = st[i];
            arr[i][1] = et[i];
            arr[i][2] = profit[i];
        }

        auto compa = [&](vector<int> &a, vector<int> &b) {
            return a[0] <= b[0];
        };
        sort(arr.begin(), arr.end(), compa);
        vector<int> dp(n,-1);
        return f(0, arr, n,dp);
    }
};

