class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> LPS(n,0);
        int i=1;
        LPS[0]=0;
        int len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else if(s[i]!=s[len]){
                if(len!=0) len=LPS[len-1];
                else {LPS[i]=0; i++;}
            }
        }
        for(auto it:LPS) cout<<it<<" ";
        if(!LPS[n-1]) return "";
        return s.substr(0,LPS[n-1]);
    }
};