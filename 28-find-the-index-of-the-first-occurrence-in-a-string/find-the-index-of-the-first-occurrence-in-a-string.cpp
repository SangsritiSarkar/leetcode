class Solution {
public:
    void computeLPS(vector<int> &LPS, string pat, int n){
        int i=1;
        int len=0;
        LPS[0]=0;
        while(i<n){
            if(pat[i]==pat[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0) len=LPS[len-1];
                else {LPS[i]=0; i++;}
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int> LPS(m,0);
        computeLPS(LPS,needle,m);

        int i=0,j=0;
        while(i<n){
            if(haystack[i]==needle[j]){i++;j++; }
            if(j==m){
                return i-m;
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0)j=LPS[j-1];
                else i++;
            }
        }
        return -1;
    }
};