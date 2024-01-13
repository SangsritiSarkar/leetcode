class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size(),ans=0;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(auto x:s) mp1[x-'a']++;
        for(auto x:t) mp2[x-'a']++;

        for(int i=0;i<26;i++)
        {
            if(mp1[i]>mp2[i]) ans+=mp1[i]-mp2[i];
        }
        return ans;
    }
};