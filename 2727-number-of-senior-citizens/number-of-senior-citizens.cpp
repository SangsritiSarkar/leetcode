class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        for(auto it:details)
        {
            string s=it.substr(11,2);
            if(s>"60") c++;
        }
        return c;
    }
};