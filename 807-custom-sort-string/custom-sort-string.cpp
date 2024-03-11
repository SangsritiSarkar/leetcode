class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        unordered_map<char,int> mp;
        for(auto c:order) mp[c]=0;
        for(auto c:s) 
          {if(mp.find(c)!=mp.end()) mp[c]++;}
        for(auto c:order)
        {
                while(mp[c]!=0) {
                    ans.push_back(c); 
                    mp[c]--;
                }    
        }
        for(auto c:s)
          {if(mp.find(c)==mp.end()) ans.push_back(c);}
        return ans;
    }
};