class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n);

        for(int i=0;i<v.size();i++) ans[i]=v[i]*v[i];
        sort(ans.begin(),ans.end());
        return ans;
    }
};