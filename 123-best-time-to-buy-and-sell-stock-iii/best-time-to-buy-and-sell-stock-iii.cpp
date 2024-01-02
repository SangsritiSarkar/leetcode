class Solution {
public:
//SPACE OPTIMIZATION
  
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<int> ahead(5,0);
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=3;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    profit=max(-val[ind]+ahead[trans+1], 0+ahead[trans]);
                }
                else
                {
                    profit=max(val[ind]+ahead[trans+1], 0+ahead[trans]);
                }
                ahead[trans]=profit;

            }
        }
        return ahead[0];
    }
};