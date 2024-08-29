class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int i=0,last=0;
        if(m>n) return -1;
       while(i<=n-m)
        {
            int j=0;
            for(;j<m;j++)
            {
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j==m) return i;
            i++;
        }
        
        return -1;
    }
};