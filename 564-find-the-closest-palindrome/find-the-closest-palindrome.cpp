class Solution {
public:
    long makepal(long left, bool even){
        long p=left;
        if(!even) left/=10;
        while(left!=0){
            p=p*10+(left%10);
            left/=10;
        }
        return p;
    }
    string nearestPalindromic(string n) {
        int len=n.size();
        int i=(len%2 ==0)?len/2 -1: len/2;
        long fh=stol(n.substr(0,i+1));

        vector<long> v;
        v.push_back(makepal(fh,len%2 ==0));
        v.push_back(makepal(fh+1,len%2 ==0));
        v.push_back(makepal(fh-1,len%2 ==0));
        v.push_back((long)pow(10,len-1)-1);
        v.push_back((long)pow(10,len)+1);

        //for(auto it:v) cout<<it<<" ";
        long minidiff, ni=stol(n),ans=LONG_MAX;
        for(auto it:v){
            if(it==ni) continue;
            if(abs(it-ni)<minidiff){
                minidiff=abs(it-ni);
                ans=it;
            }
            else if(abs(it-ni)==minidiff) ans=min(ans,it);
        }
        return to_string(ans);
    }

};