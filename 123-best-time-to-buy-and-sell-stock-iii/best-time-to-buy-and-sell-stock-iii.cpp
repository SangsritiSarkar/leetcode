class Solution {
public:
//SPACE OPTIMIZATION
    
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<vector<int>> ahead(2, vector<int> (3,0));
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0; buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy)
                    {
                        profit=max(-val[ind]+ahead[0][cap], 0+ahead[1][cap]);
                    }
                    else
                    {
                        profit=max(val[ind]+ahead[1][cap-1], 0+ahead[0][cap]);
                    }
                    ahead[buy][cap]=profit;
                }
            }
        }
        return ahead[1][2];
    }
};