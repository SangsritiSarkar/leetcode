class Solution {
public:
    int maxProfit(vector<int>& val, int fee) {
        int n=val.size();
        vector<int> ahead(2,0), curr(2,0);
        //ahead[0]=ahead[1]=0;
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    profit=max(-val[ind]-fee+ahead[0], 0+ahead[1]);
                }
                else
                {
                    profit=max(val[ind]+ahead[1], 0+ahead[0]);
                }
                curr[buy]=profit;

            }
            ahead=curr;
           
        }
        return ahead[1];
    }
};