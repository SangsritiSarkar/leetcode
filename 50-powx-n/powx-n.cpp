class Solution {
public:
    double func(double x, long long p){
        if(p==0) return 1;
        double half=func(x,p/2);
        if((p&1)==0) return half*half;
        return x*half*half;
    }
    double myPow(double x, int n) {
        long long p=n;
        if(n<0) return 1.0/func(x,-p);
        return func(x,p);
    }
};