class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size(),ans=0;
        vector<int> mp(26,0);
        
        for(auto x:s) mp[x-'a']++;
        for(auto x:t) mp[x-'a']--;

        for(int i=0;i<26;i++)
        {
            if(mp[i]>0) ans+=mp[i];
        }
        return ans;
    }
};