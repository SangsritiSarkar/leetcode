class Solution {
public:
//VARIABLE
    int maxProfit(vector<int>& val) {
        int n=val.size();
        int aheadNotBuy=0,aheadBuy=0, currNotBuy, currBuy;
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            
           
                    currBuy=max(-val[ind]+aheadNotBuy, 0+aheadBuy);
               
                    currNotBuy=max(val[ind]+aheadBuy, 0+aheadNotBuy);
                

            
            aheadNotBuy=currNotBuy;
            aheadBuy=currBuy;
        }
        return aheadBuy;
    }
};