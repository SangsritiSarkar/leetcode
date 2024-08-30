class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        for(auto it:s){
            if(it=='(') open++;
            else if(open>0 and it==')') open--;
            else if(!open and it==')') close++;
        }
        return open+close;
    }
};