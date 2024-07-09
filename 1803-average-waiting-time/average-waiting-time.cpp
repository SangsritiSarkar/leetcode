class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double t=0;
        double tt=c[0][1];
        double st=c[0][0]+c[0][1];
        for(int i=1; i<c.size();++i)
        {
            double a=c[i][0];
            if(a>st) {tt+=c[i][1]; st=a+c[i][1];}
            else {t=c[i][1]+st;
             st=t;
             tt+=t-a;}
        }
        double ans=tt/c.size();
        return ans;
    }
};