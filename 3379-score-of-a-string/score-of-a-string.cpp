class Solution {
public:
    int scoreOfString(string s) {
     int tot=0;
     for(int i=0;i<s.size()-1;i++)
     {
       tot+=abs(s[i+1]-s[i]);
     } 
     return tot;  
    }
};