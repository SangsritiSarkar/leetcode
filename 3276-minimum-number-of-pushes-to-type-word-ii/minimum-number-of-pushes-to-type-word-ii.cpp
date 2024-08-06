class Solution {
public:
    int minimumPushes(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> freq;
        int ans=0;
        for(auto it:s) freq[it]++;
        vector<pair<int,int>> f(freq.begin(),freq.end());
        sort(f.begin(),f.end(),[](const pair<char,int> &a, const pair<char, int> &b){
            return a.second>b.second;
        });
        for(int i=0;i<f.size();++i){
            auto it=f[i];
            int push=(i/8)+1;
            ans+=push*it.second;
        }
        return ans;
    }
};