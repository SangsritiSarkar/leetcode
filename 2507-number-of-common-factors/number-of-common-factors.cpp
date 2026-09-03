class Solution {
public:
    int gcd(int a,int b){
        if (b==0) return a;
        return gcd(b,a%b);
    }
    int commonFactors(int a, int b) {
        int n=gcd(a,b),c=0;
        for(int i=1;i*i<=n;++i){
            if(a%i==0 and b%i==0){
                c+=2;
                if(n/i==i) c--;
            }
        }
        return c;
    }
};