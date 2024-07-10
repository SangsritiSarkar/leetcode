class Solution {
public:
    int minOperations(vector<string>& logs) {
        int s=0;
        string prev;
        for(auto st:logs)
        {
            if(st[0]!='.') s++;
            else if(st=="../") 
            {
                if(s==0) continue;
                else s--;
            }
            prev=st;
            cout<<s<<"\n";
        }
        return s;
    }
};