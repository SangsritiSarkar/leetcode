class Solution {
public:
    int minOperations(vector<string>& logs) {
        int s=0;
        for(auto st:logs)
        {
            if(st[0]!='.') s++;
            else if(st=="../" and s!=0) s--;
        }
        return s;
    }
};