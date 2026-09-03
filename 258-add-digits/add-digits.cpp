class Solution {
public:
    int add(int n){
        if(n==0) return 0;
        return n%10 + add(n/10);
    }
   
    int addDigits(int num) {
        if(num<=9) return num;
        return addDigits(add(num));
    }
};