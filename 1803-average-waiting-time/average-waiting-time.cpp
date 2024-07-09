class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double t=0,tt=0,st=0,a,ck;
        for(int i=0; i<c.size();++i)
        {
            a=c[i][0];
            ck=c[i][1];
            if(a>st) {tt+=ck; st=a+ck;}
            else {tt+=ck+st-a;
             st+=ck;
             }
        }
        double ans=tt/c.size();
        return ans;
    }
};