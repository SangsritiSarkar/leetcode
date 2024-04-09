class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size(),c=0;
        for(int i=0;i<n;i++)
        {
            if(i<=k) c+=(t[i]>=t[k])?t[k]:t[i];
            else c+=(t[i]>=t[k])?t[k]-1:t[i];
        }
        return c;
    }
};