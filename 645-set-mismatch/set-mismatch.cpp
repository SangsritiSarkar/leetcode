class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n=v.size();
        int c=1;
        vector<int> ans;
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++) if(v[i]==v[i+1]) {ans.push_back(v[i]); break;}
        for(int i=0;i<n;i++) if(v[i]==c) c++; 
        ans.push_back(c);
        return ans;
    }
};