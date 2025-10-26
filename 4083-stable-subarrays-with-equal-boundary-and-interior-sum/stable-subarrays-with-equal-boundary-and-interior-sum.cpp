class Solution {
public:
    long long countStableSubarrays(vector<int>& v) {
        long long n=v.size(),ans=0;
        vector<long long> p(n);p[0]=v[0];
        for(int i=1;i<n;++i) p[i]=p[i-1]+v[i];
        map<pair<int, long long>,int> mp;
        for(int i=n-1;i>=0;--i){
            ans+=mp[{v[i],p[i]+(2*v[i])}];
            if(i+1<n) mp[{v[i+1],p[i+1]}]++;
        }
        return ans;
    }
};