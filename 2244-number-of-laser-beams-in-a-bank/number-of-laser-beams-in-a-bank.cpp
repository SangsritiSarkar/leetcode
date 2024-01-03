class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),p=0,c,ans=0;
        for(auto it:bank)
        {
            c=0;
            for(auto ch:it)
            {
                if(ch=='1') c++;
            }
            if(c!=0)
            {
                ans+=p*c;
                p=c;
            } 
            
        }
        return ans;
    }
};