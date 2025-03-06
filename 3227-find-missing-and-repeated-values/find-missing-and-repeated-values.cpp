class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(auto i:grid){
            for(auto j:i){
                if(mp[j]==1) ans.push_back(j);
                else mp[j]++;
            }
        }
        for(int i=1;i<=n*n;++i){
            if(mp.find(i)==mp.end()) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};