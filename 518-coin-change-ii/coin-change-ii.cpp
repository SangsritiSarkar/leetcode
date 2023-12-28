class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(amount+1, 0);
        for(int tar=0;tar<=amount;tar++)
        {
            prev[tar]=(tar%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int tar=0;tar<=amount;tar++)
            {
                int notTake=prev[tar];
                int take=0;
                if(coins[ind]<=tar) take=prev[tar-coins[ind]];//not 1+..becoz it is no of ways
                prev[tar]=take+notTake;
            }
            //prev=curr;
        }
        return prev[amount];
        
    }
};