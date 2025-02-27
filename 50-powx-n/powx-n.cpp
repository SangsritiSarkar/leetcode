class Solution {
public:
    double func(double x,long long n){
       
        if(n==1) return x;
        double half=func(x,n/2);
        if(n&1){
            return half*half*x;
        }
        else return half*half;
    }
    double myPow(double x, int n) {
        long long nn=n;
        if(nn==0) return 1;       
        else if(nn>0) return func(x,nn);
        return 1.0/func(x,-nn);
    }
    
};