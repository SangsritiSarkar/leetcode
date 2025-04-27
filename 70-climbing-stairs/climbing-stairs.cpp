class Solution {
public:

    //OPTIMAL SPACE COMPLEXITY 
    int climbStairs(int n) {
        int prev=1, prev2=1,curri;
        for(int i=2;i<=n;++i){
            curri=prev2+prev;
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};