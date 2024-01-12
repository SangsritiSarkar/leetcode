class Solution {
public:
    int count(int st, int end, string s)
    {
        int c=0;
        for(int i=st;i<end;i++)
        {
            if(vowel(s[i])) c++;
        }
        return c;

    }
    bool vowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        if(n%2!=0) return false;
        int c1=count(0,n/2,s);
        int c2=count(n/2,n,s);
        return c1==c2;
    }
};