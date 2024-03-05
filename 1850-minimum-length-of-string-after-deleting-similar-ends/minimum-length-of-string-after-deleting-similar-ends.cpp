class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r and s[l]==s[r])
        {
            char c=s[l];
            while(l<=r and s[l]==c) l++;
            while(l<=r and s[r]==c) r--; 
        }
        return (r-l+1);
    }
};