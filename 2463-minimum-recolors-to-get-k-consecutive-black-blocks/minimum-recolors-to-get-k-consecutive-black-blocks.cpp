class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),cw, mini=INT_MAX;
        for(int i=0;i<=blocks.size()-k;++i){
            cw=0;
            for(int j=i;j<k+i;++j){
                if(blocks[j]=='W') cw++;
            }
            
            mini=min(mini,cw);
        }
        return mini;
    }
};