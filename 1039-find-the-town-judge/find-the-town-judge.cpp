class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int s=trust.size();
        vector<int> v(n+1);
        for(auto it:trust)
        {
            v[it[0]]--; v[it[1]]++;
        }
        for(int i=1;i<=n;i++) 
        {
            if(v[i]==n-1) return i;
        }
        return -1;
    }
};