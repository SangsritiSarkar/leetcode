class Solution {
public:
    
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size(),ans=-1;
        unordered_map<char,int> mp;
        for (int i= 0; i < s.size(); i++) {
            char ch=s[i];
            if(mp.find(ch)==mp.end())
              mp[ch]=i;
            else
              ans=max(ans,i-mp[ch]-1);  
        }
        return ans;
    }
};