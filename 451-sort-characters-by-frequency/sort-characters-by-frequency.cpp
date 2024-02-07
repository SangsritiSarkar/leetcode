class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans;
        unordered_map<char,int> mp;
        for(auto c:s) mp[c]++;
        vector<pair<char,int>> p(mp.begin(),mp.end());
        sort(p.begin(),p.end(), [](const pair<char,int>& a, const pair<char,int>& b){
            return a.second>b.second;
        });
        for(auto it:p)
        {
            int cnt=it.second;
            char v=it.first;
            for(int i=1;i<=cnt;i++) {ans.push_back(v);}
        }
        return ans;
    }
};