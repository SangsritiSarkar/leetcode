class Solution {
public:
    void computeLPS(vector<int> &LPS, string s, int n){
        int len=0;
        int i=1;
        LPS[0]=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0) len=LPS[len-1];
                else {LPS[i]=0;i++;}
            }
        }
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string long_palin=s+"#"+rev;
        int long_size=(2*n)+1;
        vector<int> LPS(long_size,0);
        computeLPS(LPS,long_palin,long_size);
        string extra=s.substr(LPS[long_size-1],n);
        reverse(extra.begin(),extra.end());
        string ans=extra+s;
        return ans;
        
        
  

    }
};