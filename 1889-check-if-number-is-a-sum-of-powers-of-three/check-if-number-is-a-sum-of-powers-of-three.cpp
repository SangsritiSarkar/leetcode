class Solution {
public:
    bool checkPowersOfThree(int n) {
        int r;
        while(n){
            
            r=n%3;
            n=n/3;
            if(r>1) return false;
        }
        return true;
        
    }
};