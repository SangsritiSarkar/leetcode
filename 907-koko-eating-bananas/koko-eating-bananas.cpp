class Solution {
public:
    int maxEle(vector<int> &piles){
        int maxi=INT_MIN;
        for(auto it:piles){
            maxi=max(it,maxi);
        }
        return maxi;
    }
    long long req(vector<int> &piles, int k){
        long long tot=0;
        for(int i=0;i<piles.size();++i){
            tot+=ceil(double(piles[i])/double(k));
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=maxEle(piles),mid;
        long long tot=0;
        while(low<=high){
            mid=low+(high-low)/2;
            tot=req(piles,mid);
            if(tot>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};