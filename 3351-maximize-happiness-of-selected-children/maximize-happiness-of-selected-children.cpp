class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n=h.size(),turn=0;
        sort(h.rbegin(),h.rend());
        long long s=0;
        for(int i=0;i<k;i++)
        {
            s+=max(h[i]-turn,0);
            turn++;
        }
        return s;
    }
};