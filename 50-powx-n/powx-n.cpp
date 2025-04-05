class Solution {
public:
    double func(double x, long long p){
        double ans=1.0;
        while(p>0){
            if(p&1) {ans*=x; --p;}
            else {x*=x; p>>=1;}
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long p=n;
        if(n<0) return 1.0/func(x,-p);
        return func(x,p);
    }
};