class Solution {
public:

    bool closeStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        vector<int> ct1(26,0);
        vector<int> ct2(26,0);
        for(auto c:s1) ct1[c-'a']++;
        for(auto c:s2) 
        {
            if(ct1[c-'a']==0) return false;
            ct2[c-'a']++;
             
        }
        sort(ct1.begin(),ct1.end());
        sort(ct2.begin(),ct2.end());
        return(ct1==ct2);
        
    }
};