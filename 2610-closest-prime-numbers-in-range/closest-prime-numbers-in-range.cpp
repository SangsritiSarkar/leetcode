class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1,1);
        vector<int> v,ans;
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<=right;++i){
            if(isPrime[i]){

                for(int j=2*i;j<=right;j+=i) isPrime[j]=false;
            }
        }
        for(int i=left;i<=right;++i){
            if(isPrime[i]) v.push_back(i);
        }
        //int n=v.size();
        //vector<pair<int,int>> pre;
        //pre.push_back({INT_MAX,0});
        // for(int i=0;i<v.size()-1;++i)
        // {
        //     pre.push_back({v[i+1]-v[i],v[i]});
        // }
        if(v.size()<2) return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<v.size();++i)
        {
            int diff=v[i]-v[i-1];
            if(diff<mini){
                mini=diff;
                ans={v[i-1],v[i]};
            }
        }
        return ans;
        // sort(pre.begin(),pre.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        //     if(a.first==b.first) return a.second<b.second;
        //     return a.first<b.first;
        // });
        // if(pre.size()==0) return {-1,-1};
        // int n1=pre[0].second;
        // int n2=pre[0].first+n1;
        // return {n1,n2};
        
    }
};