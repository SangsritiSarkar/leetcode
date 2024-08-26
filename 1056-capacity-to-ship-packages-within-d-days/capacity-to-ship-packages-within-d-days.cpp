class Solution {
public:
    int func(vector<int>& weights, int w){
        int d=1, curr=0;
        for(auto it:weights){
            if(it+curr<=w) curr+=it;
            else{
                d++;
                curr=it;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)>>1;
            int cnt=func(weights,mid);
            if(cnt>days) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};