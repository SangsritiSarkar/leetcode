class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });
        int e=v[0][1],s=v[0][0];
        for(int i=1;i<v.size();++i){           
            if(e>=v[i][0]) {e=max(e,v[i][1]); }
            else{
                ans.push_back({s,e});
                s=v[i][0]; e=v[i][1];
            }
            
        }
        ans.push_back({s,e});
        return ans;
    }
};