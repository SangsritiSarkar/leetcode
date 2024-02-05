class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> mp;
        int ind=s.size();
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second=i;
        }
        for(auto [x,y]:mp)
        {
            if(y.first==1)
            {
                ind =min(ind,y.second);
            }
        }
        return ind==s.size()?-1:ind;
    }
};