class Solution {
public:
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<int> f2(2,0), f1(2,0),curr(2,0);
       
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            
            for(int buy=0;buy<=1;buy++)
            {
                curr[1]=max(-val[ind]+f1[0], f1[1]);
                curr[0]=max(val[ind]+f2[1], f1[0]);
            }
            f2=f1;
            f1=curr;
        }
        return curr[1];    
    }
};