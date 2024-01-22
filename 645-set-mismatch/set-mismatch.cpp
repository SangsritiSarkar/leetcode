class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n=v.size();
        vector<int> ans(2,0);
        sort(v.begin(),v.end());
        for(int i=1;i<=n;i++)
        {
            if(find(v.begin(),v.end(),i)==v.end()){
                ans[1]=i; break;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])
            {
                ans[0]=v[i];
                break;
            }
        }
        return ans;
    }
};