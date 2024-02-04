class Solution {
public:
    string minWindow(string s, string t) {
         int lens=s.size(),lent=t.size();
        unordered_map<char,int>m,check;
        for(int i=0;i<lent;i++){
            check[t[i]]++;
            m[t[i]]=0;
        }
        int ml=INT_MAX,leftind=-1,c=0;
        int l=0,r=-1;
        while(l<lens and r<lens){
            if(c!=lent){
                while(l<r and m.find(s[l])==m.end()) l++;
                r++;
                if(m.find(s[r])!=m.end()){
                    if(m[s[r]]<check[s[r]]) c++;
                    m[s[r]]++;
                }
            }
            if(c==lent){
                if(r-l+1<ml){
                    ml=r-l+1;
                    leftind=l;
                }
                if(m.find(s[l])!=m.end()){
                    m[s[l]]--;
                    if(m[s[l]]<check[s[l]]) c--;
                }
                l++;
            }
        }
        if(ml==INT_MAX) return "";
        else return s.substr(leftind,ml);
    }
};