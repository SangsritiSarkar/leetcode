class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size();
        int x=t[k];
        int c=0;
        for(int i=0;i<=k;i++)
        {
            if(t[i]>=x) c+=x;
            else c+=t[i];
        }
        for(int i=k+1;i<n;i++)
        {
            if(t[i]>=x) c+=x-1;
            else c+=t[i];
        }
        return c;
    }
};