class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double t=0,tt=0,st=0,a,ck;
        for(int i=0; i<c.size();++i)
        {
            a=c[i][0];
            ck=c[i][1];
            if(a>st) {tt+=c[i][1]; st=a+c[i][1];}
            else {tt+=ck+st-a;
             st+=ck;
             }
        }
        double ans=tt/c.size();
        return ans;
    }
};