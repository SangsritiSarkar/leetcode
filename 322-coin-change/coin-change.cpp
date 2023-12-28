class Solution {
public:
//SPACE OPTIMIZATION IN 1 ARRAY

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1, 0);
        //BASE CASE
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }
        //STATES
        for(int ind=1;ind < n;ind++)
        {
            for(int target=0;target <= amount;target++)
            {
                int notTake=0+prev[target];
                int take=1e9;
                if(coins[ind]<=target) take=1+prev[target-coins[ind]];
                prev[target]=min(take, notTake);
            }
            
        }
        if(prev[amount]>=1e9) return -1;
        return prev[amount];
        
    }
};